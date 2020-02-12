/**
 * This is the C code corresponding to algorithm 1.3 (Milestone 1)
 * Conditional execution / selection through if/else statements
 * unsigned type modifier
 * short type
 * -= and += operators
 * %hu and %.2f formating options
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
 * Notice the use of UPPER CASE as a good naming convention here
*/
#define TAX_RATE 20

int main()
{
    /**
     * In comparision with tca_2_2.c, here we changed the type of quantity
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
    unsigned short quantity, available_quantity;
    float price, net_total_price, tax, total_price;

    /* Output to the user that s/he should enter the available quantity */
    printf("Available quantity: ");
    /* Input the available_quantity from the user
     * %hu: h for half int, u for unsigned
     */
    scanf("%hu", &available_quantity);
    /* Output to the user that s/he should enter the price */
    printf("Price: ");
    /* Input the price from the user, %f is used because price is a float */
    scanf("%f", &price);
    /* Output to the user that s/he should enter the quantiy */
    printf("Ordered quantity: ");
    /* Input the quantiy from the user
     * %hu: h for half int, u for unsigned
     */
    scanf("%hu", &quantity);

    /**
     * Conditional execution / selection through if/else statements
     * if (condition) { statement_1; statement_2; ...; statement_n; }
     * else { other_statement_1; other_statement_2; ...; other_statement_m; }
     * condition is a logical expression such as quantity <= available_quantity
     * statement_1 through statement_n get executed if and only if condition is true
     * Otherwise, other_statement_1 through other_statement_m get executed.
     */
    if (quantity <= available_quantity) { /* Check whether the ordered quantity is less or equal than the availabe one */
        net_total_price = price * quantity;
        tax = net_total_price * TAX_RATE / 100;
        total_price = net_total_price + tax;
        /* Decrement available_quantity by quantity using the -= decrementation operator */
        available_quantity -= quantity;
        /* Obviously, += is the incrementation operator
        
        /* %.2f to print only 2 digits after the floating point */
        printf("\nNet Total Price: %.2f\n", net_total_price);
        printf("Tax: %.2f\n", tax);
        printf("Total Price: %.2f\n", total_price);
        printf("Remaining quantity: %hu\n", available_quantity);
    } else { /* Ordered quantity is strictly bigger than the available one */
        printf("Sorry!\n");
    }

    return 0;
}

/**
 * The list, so far, of reserved keywords (cannot be used as variable names):
 * int, float, short, unsigned, return
 * This list will keep growing, as we discover each time a new reserved keyword.
 */