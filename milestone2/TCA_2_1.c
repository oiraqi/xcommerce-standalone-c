int main() {
    /**
     * total_price, price and quantity are variables.
     * A variable represents data that is acted upon by an algorithm/program.
     * As its name implies, the value of this data may vary during the execution 
     * of the algorithm/program.
    */ 
    int total_price, price, quantity;
    /**
     * A variable has:
     * 1) a name (e.g. total_price)
     * The name of a variable can only be made of letters (from a to z
     * and from A to Z), digits (from 0 to 9) and underscore (_).
     * While the name of a variable can contain digits, it shall not start with
     * a digit. 1price is invalid, while price1 is valid.
     * Variable names are case sensitive, meaning that price and Price are two 
     * completely different variables.
     * Finally, a variable name shall not be a reserved keyword. See the list below.
     * 
     * 2) a type (e.g. int).
     * The type of a variable dictates the nature of values it can hold:
     * Natural numbers, floating-point numbers, text, etc.
     * This is very useful. More on this later...
     */

    /**
     * In the statement below, price * quantity is computed and the result is
     * memorized in total_price. More specifically, price * quantity is an expression.
     * This expression is made of two operands (price and quantity) and an operator
     * between the two (*). This expression is evaluated (computed) and its result is
     * memorized in the left-side variable (total_price) of the = symbol.
     * We also say that the result, of the expression evaluation, is assigned to total_price.
     * In this sense, the = symbol is also called the assignment operator. It assigns the
     * value of its right-side to the variable on its let-side.
     * To check the equality between two values, we use the == operator.
     */
    total_price = price * quantity;

    return 0;
}

/**
 * The list of reserved keywords (cannot be used as variable names) so far:
 * int, return
 */