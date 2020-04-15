#include <stdio.h>
#include <string.h>
#define TAX_RATE 20
#define MAX_NUMBER_OF_PRODUCTS 50
#define MAX_NUMBER_OF_CUSTOMERS 30
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_CUSTOMER_NAME_LENGTH 50
#define MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH 256

/**
 * These are GLOBAL variables, as they have to be accessed by many functions.
 * n_customers: the actual number of customers we want to handle. Must be <= MAX_NUMBER_OF_CUSTOMERS.
 * n_products: the actual number of products in our catalog. Must be <= MAX_NUMBER_OF_PRODUCTS.
 */
unsigned short n_customers, n_products;
/**
 * quantity is an array of unsigned short elements. Each of them represents the quantity of a product.
 * The number of these elements is MAX_NUMBER_OF_PRODUCTS. We also say that MAX_NUMBER_OF_PRODUCTS.
 * is the size of the quantity array. Think of these elements as boxes in memory, lying one after the other.
 * The advantage is that we can refer to all these elements using one symbol/variable name: quantity in this case,
 * and using an index from 0 to MAX_NUMBER_OF_PRODUCTS - 1 that we put between [].
 * quantity[i] represents the quantity of the ith product.
 */ 
unsigned short quantity[MAX_NUMBER_OF_PRODUCTS];

/**
 * Similarily, price is an array of float elements. Each of them represents the price of a product.
 * The number of these elements is MAX_NUMBER_OF_PRODUCTS.
 * net_total_price is an array of float elements. Each of them represents the net_total_price that must be paid by a customer.
 * The number of these elements is MAX_NUMBER_OF_CUSTOMERS.
 * tax and total_price are also arrays of float elements.
 */ 
float price[MAX_NUMBER_OF_PRODUCTS], net_total_price[MAX_NUMBER_OF_CUSTOMERS], 
tax[MAX_NUMBER_OF_CUSTOMERS], total_price[MAX_NUMBER_OF_CUSTOMERS];

/**
 * ordered_quantity is a two-dimensional array of unsigned short elements.
 * It represents the quantity ordered of each product by each customer.
 * It is like a matrix with MAX_NUMBER_OF_CUSTOMERS lines and MAX_NUMBER_OF_PRODUCTS columns.
 * orderd_quantity[ci][pi] represents the quantity ordered of product pi by customer ci.
 */
unsigned short orderd_quantity[MAX_NUMBER_OF_CUSTOMERS][MAX_NUMBER_OF_PRODUCTS];

/**
 * Each one of these variables is an array of strings.
 * Each string is itself an array of characters, delimited by '\0'.
 */
char product_name[MAX_NUMBER_OF_PRODUCTS][MAX_PRODUCT_NAME_LENGTH], 
    customer_name[MAX_NUMBER_OF_CUSTOMERS][MAX_CUSTOMER_NAME_LENGTH], 
    customer_shipping_address[MAX_NUMBER_OF_CUSTOMERS][MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH];

/**
 * These two prototypes are for functions that are used in this file only.
 * They are not part of header.h because we do not need/want them to be used/called from outside this file.
 * We prefix them with _ as a naming convention, to remind ourselves that they are not accessible outside this file.
 * _handle_customer gets called by handle_customers.
 * __handle_order gets called by handle_customer.
 * ___compute_tax_and_total_price gets called by _handle_order.
 * The number of _ in the prefix gives an idea about the order/depth of the function.
 */
void _handle_customer(int);
void __handle_order(int, int, unsigned short);
int __search_for_products(char[], int[]);
void ___compute_tax_and_total_price(int);

/**
 * Initialize stock.
 */
void init_stock() {
    /**
     * pi: product index -- local variable.
     */
    int pi;
    printf("*************Initializing Stock*************\n");
    do {
        printf("Enter the number of products (Must be less than or equal to %d): ", MAX_NUMBER_OF_PRODUCTS);
        scanf("%hu", &n_products);
    } while (n_products > MAX_NUMBER_OF_PRODUCTS);
    
    for(pi=0; pi < n_products; pi++) {
        printf("Enter the name of product %d: ", pi + 1);
        getchar();
        fgets(product_name[pi], MAX_PRODUCT_NAME_LENGTH, stdin);
        printf("Enter the available quantity of product %d: ", pi + 1);
        scanf("%hu", &quantity[pi]);
        printf("Enter the price of product %d: ", pi + 1);
        scanf("%f", &price[pi]);
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

    do {
        printf("\nHow many customers do you want to handle? (Must be less than or equal to %d): ", MAX_NUMBER_OF_CUSTOMERS);
        scanf("%hu", &n_customers);
    } while (n_customers > MAX_NUMBER_OF_CUSTOMERS);

    for (ci=0; ci < n_customers; ci++) {
        _handle_customer(ci);
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
    int ci, pi, lci = 0, hci = 0;
    float grand_net_total = 0.0, grand_tax = 0.0, grand_total = 0.0;

    printf("\n*************REPORT****************\n");

    for (ci=0; ci < n_customers; ci++) {
        printf("Customer %d\n-------------------------\n", ci + 1);
        for (pi=0; pi < n_products; pi++) {
            if (orderd_quantity[ci][pi] > 0) {
                printf("Product %d: %.2f x %d = %.2f\n", 
                    pi + 1, price[pi], orderd_quantity[ci][pi], 
                    price[pi] * orderd_quantity[ci][pi]);
            }
        }
        if (net_total_price[ci] < net_total_price[lci]) {
            lci = ci;
        } else if (net_total_price[ci] > net_total_price[hci]) {
            hci = ci;
        }
        
        grand_net_total += net_total_price[ci];
        grand_tax += tax[ci];
        grand_total += total_price[ci];
        printf("\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n\n", 
                net_total_price[ci], tax[ci], 
                total_price[ci]);
    }

    printf("*********Lowest-order Customer**********\n");
    printf("Customer: %d\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n", 
        lci + 1, net_total_price[lci], 
        tax[lci], total_price[lci]);
    
    printf("*********Highest-order Customer**********\n");
    printf("Customer: %d\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n", 
        hci + 1, net_total_price[hci], 
        tax[hci], total_price[hci]);
    
    printf("*********Grand Total**********\n");
    printf("Grand Net Total: %.2f\nGrand Tax: %.2f\nGrand Total: %.2f\n", 
        grand_net_total, grand_tax, grand_total);
    
    printf("**************STOCK************\n");
    for (pi=0; pi < n_products; pi++) {
        printf("Product %d: %d\n", pi + 1, quantity[pi]);
    }

    printf("*******************************\n");
}

/**
 * Handle one customer ci.
 * ci: customer index.
 */
void _handle_customer(int ci) {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     * pi: product index, moves between 0 and n_products.
     */
    int feedback = 1, pi, q;

    char keyword[MAX_PRODUCT_NAME_LENGTH];
    int number_of_results, search_results[MAX_NUMBER_OF_PRODUCTS];

    /**
     * Initialize the net total price for this customer.
     */
    net_total_price[ci] = 0.0;

    /**
     * Initialize ordered quantities for this customer.
     */
    for (pi=0; pi < n_products; pi++) {
        orderd_quantity[ci][pi] = 0;
    }

    printf("*************Handling a new customer*************\n");

    printf("Enter the name of customer %d: ", ci + 1);
    getchar();
    fgets(customer_name[ci], MAX_CUSTOMER_NAME_LENGTH, stdin);

    printf("Enter the shipping address of customer %d: ", ci + 1);
    getchar();
    fgets(customer_shipping_address[ci], MAX_CUSTOMER_SHIPPING_ADDRESS_LENGTH, stdin);

    do {
        printf("Specify (first) part of the product name for partial matching: ");
        getchar();
        fgets(keyword, MAX_PRODUCT_NAME_LENGTH, stdin);
        printf("%s\n", keyword);
        number_of_results = __search_for_products(keyword, search_results);
        if (!number_of_results) {
            printf("Sorry. No product found\n");
            continue; 
            /* a new keyword, which means, skip the rest of this iteration
            ** and continue directly with the next iteration of the loop.
            */
        }
        /**
         * If we are here, then necessarily products are found.
         * Display them, and invite the operator to choose one.
         */
        for (pi=0; pi < number_of_results; pi++) {
            printf("Product %d: %s (%.2f) / %d \n", search_results[pi] + 1, 
                product_name[search_results[pi]], 
                price[search_results[pi]], quantity[search_results[pi]]);
        }
        printf("Select product index: ");
        scanf("%d", &pi);
        printf("Select quantity: ");
        scanf("%d", &q);
        __handle_order(ci, --pi, q);
        printf("\nEnter 1 to continue or any other number to stop: ");
        scanf("%d", &feedback);
    } while (feedback == 1);
}

/**
 * Handle one order of product pi, by customer ci.
 * ci: ordering customer index.
 * pi: ordered product index.
 * quantity: ordered quantity.
 */
void __handle_order(int ci, int pi, 
                        unsigned short q) {
    if (pi < 0 || pi >= n_products) {
        printf("Sorry. The selected product does not exist\n");
        return;
    }
   
    if (q <= quantity[pi]) {
        net_total_price[ci] += price[pi] * q;
        quantity[pi] -= q;
        orderd_quantity[ci][pi] += q;
        ___compute_tax_and_total_price(ci);
    } else {
        printf("Sorry, ordered quantity is not available\n");
    }    
}

/**
 * Search for products whose name start with the given keyword.
 * The indices of matching products are put in search_results array.
 * The number of results is returned.
 */

int __search_for_products(char keyword[], int search_results[]) {
    int pi, number_of_results = 0;
    for (pi=0; pi < n_products; pi++) {
        if (!strncmp(product_name[pi], keyword, strlen(keyword)))
            search_results[number_of_results++] = pi;
    }
    return number_of_results;
}

/**
 * Compute the tax and total price for customer ci.
 * ci: customer index.
 */
void ___compute_tax_and_total_price(int ci) {

    tax[ci] = net_total_price[ci] * TAX_RATE / 100;
    total_price[ci] = net_total_price[ci] + tax[ci];

    printf("Net total price so far: %.2f\n", net_total_price[ci]);
    printf("Tax so far: %.2f\n", tax[ci]);
    printf("Total price so far: %.2f\n", total_price[ci]);
}
