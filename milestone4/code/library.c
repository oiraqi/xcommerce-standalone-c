#include <stdio.h>
#define TAX_RATE 20
#define MAX_NUMBER_OF_PRODUCTS 50
#define MAX_NUMBER_OF_CUSTOMERS 30

/**
 * These are GLOBAL variables, as they have to be accessed by many functions. 
 */
unsigned short n_customers, n_products;
/**
 * quantity is an array of unsigned short elements
 * Each of them represents the quantity of a product
 * The number of these elements is MAX_NUMBER_OF_PRODUCTS
 * We also say that MAX_NUMBER_OF_PRODUCTS is the size of the quantity array
 * Think of these elements as boxes in memory, lying one after the other
 * The advantage is that we can refer to all these elements using one 
 * symbol/variable name: quantity in this case, and using an index 
 * from 0 to MAX_NUMBER_OF_PRODUCTS - 1
 * quantity[i] represents the quantity of the ith product
 */ 
unsigned short quantity[MAX_NUMBER_OF_PRODUCTS];

/**
 * Similarily, price is an array of float elements
 * Each of them represents the price of a product
 * The number of these elements is MAX_NUMBER_OF_PRODUCTS
 * net_total_price is an array of float elements
 * Each of them represents the net_total_price that must be paid by a customer
 * The number of these elements is MAX_NUMBER_OF_CUSTOMERS
 * tax and total_price are also arrays of float elements
 */ 
float price[MAX_NUMBER_OF_PRODUCTS], net_total_price[MAX_NUMBER_OF_CUSTOMERS], 
tax[MAX_NUMBER_OF_CUSTOMERS], total_price[MAX_NUMBER_OF_CUSTOMERS];

/**
 * ordered_quantity is a two-dimensional array of unsigned short elements
 * It represents the quantity ordered of each product by each customer
 * It is like a matrix with MAX_NUMBER_OF_CUSTOMERS lines and MAX_NUMBER_OF_PRODUCTS columns
 * orderd_quantity[i][j] represents the quantity ordered of product j by customer i
 */
unsigned short orderd_quantity[MAX_NUMBER_OF_CUSTOMERS][MAX_NUMBER_OF_PRODUCTS];

/**
 * These two prototypes are for functions that are used in this file only.
 * They are not part of header.h because we do not need/want them to be 
 * used/called from outside this file. We prefix them with _ as a naming
 * convention, to remind ourselves that they are not accessible outside this file.
 * _handle_order gets called by handle_customer
 * __compute_tax_and_total_price gets called by _handle_order
 * The number of _ in the prefix gives an idea about the order/depth of the function
 */
void _handle_customer(int);
void __handle_order(int, int, unsigned short);
void ___compute_tax_and_total_price(int);

void init_stock() {
    int i;
    printf("*************Initializing Stock*************\n");
    do {
        printf("Enter the number of products (Must be less than or equal to %d): ", MAX_NUMBER_OF_PRODUCTS);
        scanf("%hu", &n_products);
    } while (n_products > MAX_NUMBER_OF_PRODUCTS);
    
    for(i=0; i < n_products; i++) {
        printf("Enter the available quantity of product %d: ", i + 1);
        scanf("%hu", &quantity[i]);
        printf("Enter the price of product %d: ", i + 1);
        scanf("%f", &price[i]);
    }
}

void handle_customers() {
    int i;

    do {
        printf("\nHow many customers do you want to handle? (Must be less than or equal to %d): ", MAX_NUMBER_OF_CUSTOMERS);
        scanf("%hu", &n_customers);
    } while (n_customers > MAX_NUMBER_OF_CUSTOMERS);

    for (i=0; i < n_customers; i++) {
        _handle_customer(i);
    }
}

void print_report() {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     */
    int customer_index, product_index, lowest_order_customer_index = 0, 
        highest_order_customer_index = 0;
    float grand_net_total = 0.0, grand_tax = 0.0, grand_total = 0.0, 
        lowest_net_total_price = net_total_price[0], highest_net_total_price = net_total_price[0];

    printf("\n*************REPORT****************\n");
    for (customer_index=0; customer_index < n_customers; customer_index++) {
        printf("Customer %d\n-------------------------\n", customer_index + 1);
        for (product_index=0; product_index < n_products; product_index++) {
            printf("Product %d: %.2f x %d = %.2f\n", 
                product_index + 1, price[product_index], orderd_quantity[customer_index][product_index], 
                price[product_index] * orderd_quantity[customer_index][product_index]);
        }
        if (net_total_price[customer_index] < lowest_net_total_price) {
            lowest_net_total_price = net_total_price[customer_index];
            lowest_order_customer_index = customer_index;
        }
        else if (net_total_price[customer_index] > highest_net_total_price) {
            highest_net_total_price = net_total_price[customer_index];
            highest_order_customer_index = customer_index;
        }
        
        grand_net_total += net_total_price[customer_index];
        grand_tax += tax[customer_index];
        grand_total += total_price[customer_index];
        printf("\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n\n", 
                net_total_price[customer_index], tax[customer_index], 
                total_price[customer_index]);
    }
    printf("*********Lowest-order Customer**********\n");
    printf("Customer: %d\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n", 
        lowest_order_customer_index + 1, net_total_price[lowest_order_customer_index], 
        tax[lowest_order_customer_index], total_price[lowest_order_customer_index]);
    
    printf("*********Highest-order Customer**********\n");
    printf("Customer: %d\nNet Total Price: %.2f\nTax: %.2f\nTotal Price: %.2f\n", 
        highest_order_customer_index + 1, net_total_price[highest_order_customer_index], 
        tax[highest_order_customer_index], total_price[highest_order_customer_index]);
    
    printf("*********Grand Total**********\n");
    printf("Grand Net Total: %.2f\nGrand Tax: %.2f\nGrand Total: %.2f\n", 
        grand_net_total, grand_tax, grand_total);
    
    printf("**************STOCK************\n");
    for (product_index=0; product_index < n_products; product_index++) {
        printf("Product %d: %d\n", product_index + 1, quantity[product_index]);
    }
    printf("*******************************\n");
}

void _handle_customer(int customer_index) {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     */
    int i, feedback = 1, product_index, quantity;

    /**
     * Initialize the net total price for this customer
     */
    net_total_price[customer_index] = 0.0;

    /**
     * Initialize ordered quantities for this customer
     */
    for (i=0; i < n_products; i++) {
        orderd_quantity[customer_index][i] = 0;
    }

    printf("*************Handling a new customer*************\n");
    do {
        printf("Choose a product [1 .. %d]: ", n_products);
        scanf("%d", &product_index);
        product_index--;
        if (product_index < 0 || product_index >= n_products) {
            printf("Sorry. The selected product does not exist\n");
            continue; 
            /* a new keyword, which means, skip the rest of this iteration
            ** and continue directly with the next iteration of the loop.
            */
        }
        /**
         * If we are here, then necessarily index is 1, 2 or 3
         */        
        printf("Select quantity: ");
        scanf("%d", &quantity);
        __handle_order(customer_index, product_index, quantity);
        printf("\nEnter 1 to continue or any other number to stop: ");
        scanf("%d", &feedback);
    } while (feedback == 1);
}

void __handle_order(int customer_index, int product_index, 
                        unsigned short quantiy) {
    if (product_index < 0 || product_index >= n_products) {
        printf("Sorry. The selected product does not exist\n");
        return;
    }
   
    if (quantiy <= quantity[product_index]) {
        net_total_price[customer_index] += price[product_index] * quantiy;
        quantity[product_index] -= quantiy;
        orderd_quantity[customer_index][product_index] += quantiy;
        ___compute_tax_and_total_price(customer_index);
    } else {
        printf("Sorry, ordered quantity is not available\n");
    }    
}

void ___compute_tax_and_total_price(int customer_index) {

    tax[customer_index] = net_total_price[customer_index] * TAX_RATE / 100;
    total_price[customer_index] = net_total_price[customer_index] + tax[customer_index];

    printf("Net total price so far: %.2f\n", net_total_price[customer_index]);
    printf("Tax so far: %.2f\n", tax[customer_index]);
    printf("Total price so far: %.2f\n", total_price[customer_index]);
}
