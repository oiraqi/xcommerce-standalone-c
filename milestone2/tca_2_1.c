/**
 * This is the C code corresponding to algorithm 1.1 (Milestone 1)
 * Introducing basics of C programming
 * Author: Omar IRAQI - o.iraqi@aui.ma | o.iraqi@gmail.com
 */

int main() {
    /**
     * total_price, price and quantity are variables.
     * A variable represents data that is acted on by an algorithm/program.
     * As its name implies, the value of this data may vary during the execution 
     * of the algorithm/program.
    */ 
    float price, total_price;
    int quantity;
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
     * Finally, a variable name shall not be a reserved keyword. See the list below.
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

    return 0;
}

/**
 * The list of reserved keywords (cannot be used as variable names) so far:
 * int, float, return
 * This list will keep growing, as we discover each time a new reserved keyword.
 */