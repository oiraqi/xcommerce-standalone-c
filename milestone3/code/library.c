#include <stdio.h>
#define TAX_RATE 20

/**
 * These are GLOBAL variables, as they have to be accessed by many functions. 
 */
unsigned short qa1, qa2, qa3;
float price1, price2, price3, net_total_price;

/**
 * These two prototypes are for functions that are used in this file only.
 * They are not part of header.h because we do not need/want them to be used/called from outside this file.
 * We prefix them with _ as a naming convention, to remind ourselves that they are not accessible outside this file.
 * _handle_order gets called by handle_customer.
 * __compute_tax_and_total_price gets called by _handle_order.
 * The number of _ in the prefix gives an idea about the order/depth of the function.
 */
void _handle_order(unsigned short, unsigned short);
void __compute_tax_and_total_price();

/**
 * Initialize stock.
 */
void init_stock() {
    printf("*************Initializing Stock*************\n");
    printf("Enter the available quantity of product 1: ");
    scanf("%hu", &qa1);
    printf("Enter the price of product 1: ");
    scanf("%f", &price1);

    printf("Enter the available quantity of product 2: ");
    scanf("%hu", &qa2);
    printf("Enter the price of product 2: ");
    scanf("%f", &price2);

    printf("Enter the available quantity of product 3: ");
    scanf("%hu", &qa3);
    printf("Enter the price of product 3: ");
    scanf("%f", &price3);
}

/**
 * Handle customer.
 */
void handle_customer() {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     */
    int feedback = 1, index, quantity;
    net_total_price = 0.0;
    printf("*************Handling a new customer*************\n");
    do {
        printf("Choose product [1, 2, 3]: ");
        scanf("%d", &index);
        if (index < 1 || index > 3) {
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
        _handle_order(index, quantity);
        printf("\nEnter 1 to continue or any other number to stop: ");
        scanf("%d", &feedback);
    } while (feedback == 1);
}

/**
 * Handle one order.
 * index: ordered product.
 * quantity: ordered quantity.
 */
void _handle_order(unsigned short index, unsigned short quantiy) {
    switch (index) {
        case 1:
            if (quantiy <= qa1) {
                net_total_price += price1 * quantiy;
                qa1 -= quantiy;
                __compute_tax_and_total_price();
            } else {
                printf("Sorry, ordered quantity is not available\n");
            }
        break;
        case 2:
            if (quantiy <= qa2) {
                net_total_price += price2 * quantiy;
                qa2 -= quantiy;
                __compute_tax_and_total_price();
            } else {
                printf("Sorry, ordered quantity is not available\n");
            }
        break;
        case 3:
            if (quantiy <= qa3) {
                net_total_price += price1 * quantiy;
                qa3 -= quantiy;
                __compute_tax_and_total_price();
            } else {
                printf("Sorry, ordered quantity is not available\n");
            }
        break;
        default:
            printf("Sorry. The selected product does not exist\n");
    }    
}

/**
 * Compute tax and total price.
 */
void __compute_tax_and_total_price() {
    /**
     * These are LOCAL variables. Their scope is limited to this function block.
     */
    float tax, total_price;

    tax = net_total_price * TAX_RATE / 100;
    total_price = net_total_price + tax;

    printf("Net total price so far: %.2f\n", net_total_price);
    printf("Tax so far: %.2f\n", tax);
    printf("Total price so far: %.2f\n", total_price);
}

