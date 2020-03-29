/**
 * This is the C code corresponding to algorithm 1.4 (Milestone 1)
 * Conditional execution / selection through if/else if/else statements
 * Author: Omar IRAQI - o.iraqi@aui.ma | o.iraqi@gmail.com
 */

/**
 * For printf and scanf (see below) to be recognized by the compiler.
 * More on this later. Just accept it and use it as is for now
*/
#include <stdio.h>

/**
 * Define TAX_RATE to be equivalent to 20
 * Can't be changed to a different value, as this is not a variable
 * Notice the use of UPPER CASE as a good naming convention here.
 * 
 * All occurences of TAX_RATE will be changed to 20 by the preprocessor,
 * which is part of the compiler, before compiling the code.
*/
#define TAX_RATE 20

int main()
{
    /**
     * In comparision with tca_2_3.c, here we added index, available_quantity_1, 
     * available_quantity_2, available_quantity_3, price1, price2, and price3 variables.
    */
    unsigned short quantity, index, available_quantity_1, available_quantity_2, available_quantity_3;
    float price1, price2, price3, net_total_price, tax, total_price;

    printf("Available quantity of product 1: ");
    scanf("%hu", &available_quantity_1);
    printf("Price of product 1: ");
    scanf("%f", &price1);

    printf("Available quantity of product 2: ");
    scanf("%hu", &available_quantity_2);
    printf("Price of product 2: ");
    scanf("%f", &price2);

    printf("Available quantity of product 3: ");
    scanf("%hu", &available_quantity_3);
    printf("Price of product 3: ");
    scanf("%f", &price3);

    printf("Select product (1, 2, 3): ");
    scanf("%hu", &index);
    
    /* Output to the user that s/he should enter the quantiy */
    printf("Ordered quantity: ");
    scanf("%hu", &quantity);

    /**
     * Conditional execution / selection through if / else if / else statements
     * if (condition_1) { statement_1_1; statement_1_2; ... }
     * else if (condition_2) { statement_2_1; statement_2_2; ... }
     * ...
     * else if (condition_n) { statement_n_1; statement_n_2; ... }
     * else { other_statement_1; other_statement_2; ... other_statement_m; }
     * condition_i is checked if and only if condition_j is false for all j such that 1 <= j < i
     * other_statement_1 through other_statement_m get executed if and only if all condition_i 
     * are false for 1 <= i <= n
     */
    if (index == 1) { /* Notice the use of == operator for comparison, NOT = */
        if (quantity <= available_quantity_1) {
            net_total_price = price1 * quantity;
            available_quantity_1 -= quantity;
        } else {
            printf("Sorry!\n");
            return 1;
        }
    } else if (index == 2) { /* Notice the use of == operator for comparison, NOT = */
        if (quantity <= available_quantity_2) {
            net_total_price = price2 * quantity;
            available_quantity_2 -= quantity;
        } else {
            printf("Sorry!\n");
            return 2;
        }
    } else if (index == 3) { /* Notice the use of == operator for comparison, NOT = */
        if (quantity <= available_quantity_3) {
            net_total_price = price3 * quantity;
            available_quantity_3 -= quantity;
        } else {
            printf("Sorry!\n");
            return 3;
        }
    } else {
        printf("Sorry!\n");
        return -1;
    }

    /* If the execution reaches this point, this means that index is either 1, 2 or 3, 
     * and the ordered quantity is available. Otherwise the execution would have
     * terminated earlier through one of the return statements above.
     */
    tax = net_total_price * TAX_RATE / 100;
    total_price = net_total_price + tax;

    printf("\nNet Total Price: %.2f\n", net_total_price);
    printf("Tax: %.2f\n", tax);
    printf("Total Price: %.2f\n", total_price);

    return 0;
}

/**
 * The list, so far, of reserved keywords (cannot be used as variable names):
 * int, float, short, unsigned, return, if, else
 * This list will keep growing, as we discover each time a new reserved keyword.
 */