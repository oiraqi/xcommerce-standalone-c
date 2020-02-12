/**
 * This is the C code corresponding to algorithm 1.1 (Milestone 1)
 * Introducing basics of C programming
 * Author: Omar IRAQI - o.iraqi@aui.ma | o.iraqi@gmail.com
 */

/**
 * For printf and scanf (see below) to be recognized by the compiler.
 * More on this later. Just accept it and use it as is for now.
*/
#include <stdio.h>
#define TAX_RATE 20

int main() {
    /**
     * In comparision with tca_2_1.c, here we add two more 
     * variables, both of type float: net_total_price and tax
    */
    int quantity;
    float price, net_total_price, tax, total_price;

    /* Output to the user that s/he should enter the price */
    printf("Price: ");
    /* Input the price from the user, %f is used because price is a float */
    scanf("%f", &price);
    /* Output to the user that s/he should enter the quantiy */
    printf("Quantiy: ");
    /* Input the quantiy from the user, %d is used because quantity is a decimal (an integer) */
    scanf("%d", &quantity);

    net_total_price = price * quantity;
    tax = net_total_price * TAX_RATE / 100;
    total_price = net_total_price + tax;
    /**
     * Output net total price, taxt and total price  to the user.
     * %f will be substitued each time by the value of the specified variable 
     * \n is a special character that represents going back to a new line
    */
    printf("Net Total Price: %f\n", net_total_price);
    printf("Tax: %f\n", tax);
    printf("Total Price: %f\n", total_price);

    return 0;
}

/**
 * The list, so far, of reserved keywords (cannot be used as variable names):
 * int, float, return
 * This list will keep growing, as we discover each time a new reserved keyword.
 */