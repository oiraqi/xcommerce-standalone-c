/**
 * This is the C code corresponding to algorithm 1.5 (Milestone 1)
 * Repetition / Loops using do { ... } while ( ... );
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
     * In comparision with tca_2_4.c, here we changed the type of quantity
     * from int type to the more suitable unsigned short type.
     * We also added one more variable available_quantity, of type unsigned short.
     * 
     * Variables of type short consume less memory than variables of type int.
     * Consequently, the range of int values, typically [|-2^31, 2^31|[, is
     * bigger than the range of short values, typically [|-2^15, 2^15|[.
     * In our case, the short range is enough for quantity and available_quantity values.
     * 
     * unsigned is a modifier that can be applied to numerical types, such as short,
     * int and float to restrict their values to positive ones.
     * Without adding unsigned modifier to the type (short in this case),
     * the numerical variable can take positive, as well as negative values.
     * The typical range of unsigned short values is [|0, 2^16|[, while
     * the typical range of unsigned int values is [|0, 2^32[.
    */
    unsigned short quantity, index, available_quantity_1, available_quantity_2, available_quantity_3;
    float price1, price2, price3, net_total_price, tax, total_price;
    int success, feedback;

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

    net_total_price = 0;

    /* do { statement_1; ... statement_n; } while (condition); */
    do { /* Entering the loop */
        success = 1;

        printf("Select product (1, 2, 3): ");
        scanf("%hu", &index);

        /* Output to the user that s/he should enter the quantiy */
        printf("Ordered quantity: ");
        scanf("%hu", &quantity);

        if (index == 1) { /* Notice the use of == operator for comparison, NOT = */
            if (quantity <= available_quantity_1) {
                net_total_price += price1 * quantity;
                available_quantity_1 -= quantity;
            } else {
                success = 0;
            }
        }
        else if (index == 2) { /* Notice the use of == operator for comparison, NOT = */
            if (quantity <= available_quantity_2) {
                net_total_price += price2 * quantity;
                available_quantity_2 -= quantity;
            } else {
                success = 0;
            }
        } else if (index == 3) { /* Notice the use of == operator for comparison, NOT = */
            if (quantity <= available_quantity_3) {
                net_total_price += price3 * quantity;
                available_quantity_3 -= quantity;
            } else {
                success = 0;
            }
        } else {
            success = 0;
        }

        if (success) { /* equivalent to if (success != 0) because a numeric value is true if and only if it is different from 0 */
            tax = net_total_price * TAX_RATE / 100;
            total_price = net_total_price + tax;

            printf("\nNet Total Price: %.2f\n", net_total_price);
            printf("Tax: %.2f\n", tax);
            printf("Total Price: %.2f\n", total_price);
        } else {
            printf("Sorry!\n");
        }

        printf("\nEnter 1 to continue or any other number to stop: ");
        scanf("%d", &feedback);
    } while (feedback == 1); /* Reexecute the loop if feedback is equal to 1, otherwise exit the loop */
    /* The value of feedback here is necessarily different from 1, 
     * otherwise we would still be in the loop */

    return 0;
}

/**
 * The list, so far, of reserved keywords (cannot be used as variable names):
 * int, float, short, unsigned, return, if, else, switch, case, break, do, while
 * This list will keep growing, as we discover each time a new reserved keyword.
 */