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

int main() {
    /**
     * total_price, price and quantity are variables.
     * A variable represents data that is acted on by an algorithm/program.
     * As its name implies, the value of this data may vary during the execution
     * of the algorithm/program.
    */
    int quantity;
    float price, total_price;
    /**
     * A variable has:
     * 1) a name (e.g. total_price)
     * The name of a variable can only be made of letters (from a to z
     * and from A to Z), digits (from 0 to 9) and underscore (_).
     * While the name of a variable can contain digits, it shall not start with
     * a digit. 1price is invalid, while price1 is valid.
     * Variable names are case sensitive, meaning that price and Price are two 
     * completely different variables.
     * As a good practice, give your variables meaningful, lower-case names, and if
     * they are made of more than one term, then separate the terms with _. Ex. total_price.
     * Finally, a variable name shall not be a reserved keyword. See the list at the end of this file.
     * 
     * 2) a type (e.g. int).
     * The type of a variable dictates the nature of values it can hold:
     * Natural numbers, floating-point numbers, text, etc.
     * This is very useful. More on this later...
     * 
     * Variables must be declared before being used in the rest of the program.
     * Variable declaration consists of specifying its type and name.
     * Ex. int quantiy;
     * Variables of the same type can be declared on the same line, separated by a comma.
     * Ex. float price, total_price;
     */

    /* Output to the user that s/he should enter the price */
    printf("Price: ");
    /* Input the price from the user, %f is used because price is a float */
    scanf("%f", &price);
    /* Output to the user that s/he should enter the quantiy */
    printf("Quantiy: ");
    /* Input the quantiy from the user, %d is used because quantity is a decimal (an integer) */
    scanf("%d", &quantity);

    /**
     * In the statement below, price * quantity is computed and the result is
     * memorized in total_price. More specifically, price * quantity is an expression.
     * This expression is made of two operands (price and quantity) and an operator
     * between the two (*). This expression is evaluated (computed) and its result is
     * memorized in the left-side variable (total_price) of the = symbol.
     * We also say that the result, of the expression evaluation, is assigned to total_price.
     * In this sense, the = symbol is also called the assignment operator. It assigns the
     * value of its right-side to the variable on its left-side.
     */
    total_price = price * quantity;
    /**
     * To check the equality between two values, we rather use the == operator.
     * Ex: a == b
     * This is a logical expression that checks whether the value of the variable a is
     * equal to the value of the variable b, without affecting/changing any of the values.
     */

    /**
     * Output total price to the user. %f will be substitued by
     * the value of total_price variable, as computed above (price * quantity)
     * \n is a special character that represents going back to a new line
    */
    printf("Total Price: %f\n", total_price);

    return 0;
}

/**
 * The list, so far, of reserved keywords (cannot be used as variable names):
 * int, float, return
 * This list will keep growing, as we discover each time a new reserved keyword.
 */