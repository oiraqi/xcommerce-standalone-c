#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAX_RATE 20
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_CUSTOMER_NAME_LENGTH 50
#define MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH 256

/**
 * User-defined Data Types
 */

typedef struct {
    char name[MAX_CUSTOMER_NAME_LENGTH];
    char shipping_address[MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH];    
} customer_t;

typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME_LENGTH];
    float price;
} product_t;

typedef struct {
    product_t *product;
    unsigned short quantity;
} quantified_product_t;

typedef struct {
    customer_t *customer;
    quantified_product_t *ordered_products;
    int n_ordered_products;
    float net_total_price;
    float tax;
    float total_price;
} order_t;

/**
 * These are GLOBAL variables, as they have to be accessed by many functions.
 * n_customers: the number of customers we want to handle.
 * n_products: the number of products in our catalog.
 * stocked_products: pointing to stocked products
 * orders: pointing to orders
 */
unsigned short n_customers, n_products;
quantified_product_t *stocked_products;
order_t *orders;


/**
 * These prototypes are for functions that are used in this file only.
 * They are not part of header.h because we do not need/want them to be used/called from outside this file.
 * We prefix them with _ as a naming convention, to remind ourselves that they are not accessible outside this file.
 * _handle_order gets called by handle_customers.
 * __handle_ordered_products gets called by handle_customer.
 * ___compute_tax_and_total_price gets called by _handle_order.
 * The number of _ in the prefix gives an idea about the order/depth of the function.
 */
void _handle_order(order_t*);
void __handle_ordered_product(order_t*, int, unsigned short);
void __search_for_products(const char*);
void ___compute_tax_and_total_price(order_t*);
char* _gets(char*, long);

/**
 * Initialize stock.
 */
void init_stock() {
    
    int pi;
    quantified_product_t *qp;
    printf("*************Initializing Stock*************\n");
    printf("Enter the number of products: ");
    scanf("%hu", &n_products);
    stocked_products = (quantified_product_t *)malloc(n_products * sizeof(quantified_product_t));
    
    for(pi=0, qp=stocked_products; pi < n_products; pi++, qp++) {
        qp->product = (product_t*)malloc(sizeof(product_t));
        qp->product->id = pi + 1;
        printf("Enter the name of product %d: ", pi + 1);
        getchar();
        _gets(qp->product->name, MAX_PRODUCT_NAME_LENGTH);
        printf("Enter the price of product %d: ", pi + 1);
        scanf("%f", &(qp->product->price));
        printf("Enter the available quantity of product %d: ", pi + 1);
        scanf("%hu", &(qp->quantity));
    }
}

/**
 * Handle all (n_customers) customers.
 */
void handle_customers() {
    /**
     * ci: customer index -- local variable.
     */
    int ci;
    order_t *order;

    printf("\nHow many customers do you want to handle?: ");
    scanf("%hu", &n_customers);
    
    orders = (order_t *)malloc(n_customers * sizeof(order_t));

    for (ci=0, order=orders; ci < n_customers; ci++, order++) {
        _handle_order(order);
    }
}

/**
 * Print a report about all orders placed by all customers.
 */
void print_report() {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     * ci: customer index, moves between 0 and n_customers.
     * pi: product index, moves between 0 and n_products.
     * lci: lowest-order customer index, keeps track of the customer with the lowest order.
     * hci: highest-order customer index, keeps track of the customer with the highest order.
     */
    int ci, pi;
    float grand_net_total = 0.0, grand_tax = 0.0, grand_total = 0.0;
    quantified_product_t *qp;
    order_t *order;
    /**
     * Let's open a file for writing.
     * We shouldn't forget to close it once done.
     * fout represents our gateway to the open file.
     */
    FILE *fout = fopen("report.txt", "w");

    fputs("\n*************REPORT****************\n", fout);

    for (ci=0, order=orders; ci < n_customers; ci++, order++) {
        fprintf(fout, "Customer %d\n-------------------------\n", ci + 1);
        fprintf(fout, "Name: %s\n", order->customer->name);
        fprintf(fout, "Shipping address: %s\n", order->customer->shipping_address);
        for (pi=0, qp=order->ordered_products; pi < order->n_ordered_products; pi++, qp++) {
            fprintf(fout, "Product %d: %.2f x %d = %.2f\n", 
                qp->product->id, qp->product->price, qp->quantity, 
                qp->product->price * qp->quantity);            
        }
        
        grand_net_total += order->net_total_price;
        grand_tax += order->tax;
        grand_total += order->total_price;

        fprintf(fout, "\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n\n", 
                order->net_total_price, order->tax, order->total_price);
    }

    fputs("\n*********Grand Total**********\n", fout);
    fprintf(fout, "Grand Net Total: %.2f\nGrand Tax: %.2f\nGrand Total: %.2f\n", 
        grand_net_total, grand_tax, grand_total);
    
    fprintf(fout, "\n**************STOCK************\n");
    
    for (pi=0, qp = stocked_products; pi < n_products; pi++, qp++) {
        fprintf(fout, "Product %d - %s: %d\n", pi + 1, qp->product->name, qp->quantity);
    }

    fputs("*******************************", fout);

    /**
     * Let's close the file as promised!
     */
    fclose(fout);
}

/**
 * Handle one order.
 */
void _handle_order(order_t *order) {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     * pi: product index, moves between 0 and n_products.
     */
    int feedback = 1, pi, q;

    char keyword[MAX_PRODUCT_NAME_LENGTH];
    int number_of_results;
    quantified_product_t *qp;
    quantified_product_t **search_results;

    order->customer = (customer_t *)malloc(sizeof(customer_t));

    /**
     * Initialize the net total price for this customer.
     */
    order->net_total_price = 0;
    order->ordered_products = (quantified_product_t *)malloc(n_products * sizeof(quantified_product_t));
    order->n_ordered_products = 0;

    /**
     * Initialize ordered quantities for this customer.
     */
    for (pi=0, qp=order->ordered_products; pi < n_products; pi++, qp++) {
        qp->quantity = 0;
    }

    printf("*************Handling a new customer*************\n");

    printf("Enter the name of the customer: ");
    getchar();
    _gets(order->customer->name, MAX_CUSTOMER_NAME_LENGTH);

    printf("Enter the shipping address of customer: ");
    getchar();
    _gets(order->customer->shipping_address, MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH);

    do {
        printf("Specify (first) part of the product name for partial matching: ");
        //getchar();
        _gets(keyword, MAX_PRODUCT_NAME_LENGTH);
        printf("%s\n", keyword);
        search_results = (quantified_product_t **)malloc(n_products * sizeof(quantified_product_t *));
        __search_for_products(keyword);
        printf("Select product index: ");
        scanf("%d", &pi);
        printf("Select quantity: ");
        scanf("%d", &q);
        __handle_ordered_product(order, pi, q);
        printf("\nEnter 1 to continue or any other number to stop: ");
        scanf("%d", &feedback);
    } while (feedback == 1);
}

/**
 * Handle one order of product pi, by order->customer.
 * pi: ordered product index.
 * quantity: ordered quantity.
 */
void __handle_ordered_product(order_t *order, int pi, 
                        unsigned short q) {
    int i;
    quantified_product_t *sp, *op;
    if (pi < 1 || pi > n_products) {
        printf("Sorry. The selected product does not exist\n");
        return;
    }

    for(i=1, sp=stocked_products; i < pi; i++, sp++);
   
    if (q > sp->quantity) {
        printf("Sorry, ordered quantity is not available\n");
        return;
    }

    order->net_total_price += sp->product->price * q;
    sp->quantity -= q;
        
    for(i=0, op = order->ordered_products; i < order->n_ordered_products; i++, op++) {
        if(op->product->id == sp->product->id) {
            op->quantity += q;
            break;
        }
    }
    if(i == order->n_ordered_products) {
        op->product = sp->product;
        op->quantity = q;
        order->n_ordered_products++;
    }
    ___compute_tax_and_total_price(order); 
}

/**
 * Search for products whose name start with the given keyword.
 * Uses strncmp from string.h.
 */

void __search_for_products(const char *keyword) {
    int pi, found = 0;
    quantified_product_t *qp = stocked_products;
    for (pi=0; pi < n_products; pi++, qp++) {
        if (!strncmp(qp->product->name, keyword, strlen(keyword))) {
            found = 1;
            printf("Product %d: %s (%.2f) / %d\n", qp->product->id, qp->product->name, 
                        qp->product->price, qp->quantity);
        }
    }
    if (!found) {
        printf("Sorry. No product found\n");
    }
}

/**
 * Compute the tax and total price for order.
 */
void ___compute_tax_and_total_price(order_t *order) {

    order->tax = order->net_total_price * TAX_RATE / 100;
    order->total_price = order->net_total_price + order->tax;

    printf("Net total price so far: %.2f\n", order->net_total_price);
    printf("Tax so far: %.2f\n", order->tax);
    printf("Total price so far: %.2f\n", order->total_price);
}

char* _gets(char *s, long max) {
    char *result = fgets(s, max, stdin);
    if (result)
        s[strlen(s) - 1] = '\0'; /* to get rid of '\n' */
    return s;
}
