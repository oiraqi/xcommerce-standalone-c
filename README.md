# Telecommerce Application
Welcome to the Telecommerce Application: a holistic and incremental project developed in, and showcasing the C programming language. Telecommerce Application is part of the overarching [XCommerce](https://github.com/oiraqi/xcommerce) meta-project.

## Overview
Intergalactic Ltd. makes a catalog of its products available both online (on its website) and offline (printed format). Customers browse the catalog (online or offline), and call Intergalactic to order selected products (hence *Tele*commerce). An Intergalactic employee answers calls, receives and processes orders.

As orders have been steadily growing, Intergalactic has realized that it needs a computer program to allow its employee process calls faster and without errors. As a matter of fact, not only has the process been too slow, increasing the number of lost customers, but it has also been affected by human errors: frequent errors in calculating total price, discount and VAT, other errors were related to stock management, etc.

This project is about developing such a computer program (Telecommerce Application) for Intergalactic company.

## ILOs
- Apply the algorithmic thinking and approach in problem-solving, and be able to express algorithms using pseudo code and flow charts
- Apply C data types, expressions, selections and repetitions, in order to translate algorithms to programs
- Apply the process of writing, compiling, debugging and testing C programs using a modern IDE (currently VS Code), as well as sharing them through a version control system (currently Git)
- Apply the top-down/divide-and-conquer approach for more advanced problems, in order to break them down into simpler sub-problems, while focusing on the high-level solution
- Identify C header and source files required by a program, and be able to organize it accordingly, in order to promote modularity
- Apply various features of C programming including pointers, arrays and strings, and ultimately user-defined data types and files
- Explain the purpose of a C program that is written by others, and analyze whether it compiles and runs successfully

## Related Material
- [Introduction to Computer Programming](https://docs.google.com/presentation/d/1kbHYSNY1zxqZXxcYxdkfULK5dRZ42IeiKI_z0pE6SN0/edit?usp=sharing)
- [Algorithms](https://docs.google.com/presentation/d/1oe6NSNcz9tKE_XYgdV7bV7XLiNyn81HFcYLmKn1ECaw/edit?usp=sharing)
- [Top/Down Approach](https://docs.google.com/presentation/d/1MMt0wCU1iK8JAOL-SSjzq4mcDM2VQKTG3TH8Pxhirkk/edit?usp=sharing)

## Milestone 1: Basic Specifications / Algorithms Only
1.1. We start by considering a **single-product** catalog. Each customer calls and specifies the quantity of the product (the only one available) s/he wants to order. The operator shall use the Telecommerce Application to compute the total price.
- Identify the problem input and output
- Design the algorithm and express it as a flow chart

1.2. In addition to the total price, the operator needs to compute the VAT too (20%)
- Update the problem input and output
- Enhance your algorithm and corresponding flow chart

1.3. We add now a **constraint**. When the customer calls and specifies the quantity to order, the Telecommerce Application shall check first the availability of the product, compute the total price and VAT if and only if the ordered quantiy is available, or give an error message otherwise ("Ordered quantity unavailable").
- Enhance your algorithm and corresponding flow chart

1.4. We consider now a **three-produc**t catalog. Each product has its own price. A customer can call and specify one (and only one) product to order, along with the desired quantity. The operator shall use the Telecommerce Application to compute the total price, as well as the VAT if and only if the ordered quantity of the selected product is available, or give an error message otherwise ("Ordered quantity uavailable").
- Identify the problem input and output
- Design the algorithm and express it as a flow chart

1.5. We still consider a three-product catalog. However, a customer may call and specify one or more products to order, along with their respective quantities. The customer can specify the same product many times, e.g. 3 x Product1, then 2 x Product2, then 1 x Product1.
- Enhance your algorithm and corresponding flow chart

Go to [Milestone 1](https://github.com/oiraqi/xcommerce-standalone-c/tree/master/milestone1)

## Milestone 2: Introduction To C Programming
*Prerequisites*
- Git installed
- Gcc (MinGW for Windows) installed
- VS Code installed

*Starting Point*
- git clone https://github.com/oiraqi/xcommerce-standalone-c.git
- cd xcommerce-standalone-c
- code .
- There you go!

For each algorithm above (1.1 through 1.5):
- Identify constants, variables and the most appropriate type of each variable
- Translate the algorithm to a C program
- Compile it
- Test it
- Share it

Go to [Milestone 2](https://github.com/oiraqi/xcommerce-standalone-c/tree/master/milestone2)

## Milestone 3: Top-down Approach / C Functions / Multi-file Programming / Partial Code Compiling
Now, we would like to handle *n* customers (calls), one after the other. And just like 1.5, each customer may order one or more products from the thtree-product catalog, again and again, until s/he's done. Then the operator, moves to the next customer.
Before receiving any call, the operator must first initialize the stock by setting the price and quantity of each product.

Related material: [Top/Down Approach](https://docs.google.com/presentation/d/1MMt0wCU1iK8JAOL-SSjzq4mcDM2VQKTG3TH8Pxhirkk/edit?usp=sharing)

Go to [Milestone 3](https://github.com/oiraqi/xcommerce-standalone-c/tree/master/milestone3)

## Milestone 4: Simple Arrays / Multi-dimensional Arrays
Here, we will no more be bound to just three products. We will consider a multi-product catalog, i.e., a catalog that can contain any number of products. Moreover, **after** hadling all customers, Intergalactic Ltd. wants to have a **detailed report** about all the placed orders.

Go to [Milestone 4](https://github.com/oiraqi/xcommerce-standalone-c/tree/master/milestone4)

## Milestone 5: Strings
In this milestone, we add product names, customer names, as well as customer shipping addresses. Also, instead of specifying the product index, customers will specify the product name. The operator shall be able to list corresponding products based on same-start partial matching (e.g. sam and samsung match partially).

Go to [Milestone 5](https://github.com/oiraqi/xcommerce-standalone-c/tree/master/milestone5)

## Milestone 6: Pointers and Files
In this milestone, we add the capability of printing the report into a file.

## Milestone 7: Encapsulation / User-defined Data Types
- typedef struct {...} customer_t;
- typedef struct {...} product_t;
- typedef struct {...} order_t;
