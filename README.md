# Telecommerce Application
Welcome to the Telecommerce Application: a holistic and incremental project developed in, and showcasing the C programming language. Telecommerce Application is part of the overarching [XCommerce](https://github.com/oiraqi/xcommerce) meta-project.

## Overview
Intergalactic Ltd. makes a catalog of its products available both online (on its website) and offline (printed format). Customers browse the catalog (online or offline), and call Intergalactic to order selected products (hence *Tele*commerce). An Intergalactic employee answers calls, receives and processes orders.

As orders have been steadily growing, Intergalactic has realized that it needs a computer program to allow its employee process calls faster and without errors. As a matter of fact, not only was the process too slow increasing the number of lost customers, but it was also affected by human errors: frequent errors in calculating total price, discount and VAT, other errors were related to stock management, etc.

This project is about developing such a computer program (Telecommerce Application) for Intergalactic company.

## ILOs
- Apply the algorithmic thinking and approach in problem-solving, and be able to express algorithms using pseudo code and flow charts
- Apply C data types, expressions, selections and repetitions, in order to translate algorithms to programs
- Apply the process of writing, compiling, debugging and testing C programs using a modern IDE (currently VS Code), as well as sharing them through a version control system (currently Git)
- Apply the top-down/divide-and-conquer approach for more advanced problems, in order to break them down into simpler sub-problems, while focusing on the high-level solution
- Identify C header and source files required by a program, and be able to organize it accordingly, in order to promote modularity
- Apply various features of C programming including pointers, arrays and strings, and ultimately user-defined data types and files
- Explain the purpose of a C program that is written by others, and analyze whether it compiles and runs successfully

## Milestone 1 (Basic specifications, algorithms only)
1.1. We start by considering a single-product catalog. Each customer calls and specifies the quantity of the product (the only one available) s/he wants to order. The operator shall use the Telecommerce Application to compute the total price.
- Identify the problem input and output
- Design the algorithm and express it as a flow chart

1.2. In addition to the total price, the operator needs to compute the VAT too (20%)
- Update the problem input and output
- Enhance your algorithm and corresponding flow chart

1.3. We add now a constraint. When the customer calls and specifies the quantity to order, the Telecommerce Application shall check first the availability of the product, compute the total price and VAT if and only the orderd quantiy is available, or give an error message otherwise ("Orderd quantity unavailable").

1.4. We consider now a three-product catalog. Each product has its own price. A customer can call and specify one (and only one) product to order, along with the desired quantity. The operator shall use the Telecommerce Application to compute the total price, as well as the VAT if and only if the ordered quantity of the selected product is available, or give an error message otherwise ("Ordered quantity uavailable").
- Identify the problem input and output
- Design the algorithm and express it as a flow chart

1.5. We still consider a three-product catalog. However, a customer may call and specify one or more products to order, along with their respective quantities. The customer can specify the same product many times, e.g. 3 x Product1, 2 x Product2, 1 x Product1

## Milestone 2
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
- Translate the algorithm a C program
- Compile it
- Test it
- Share it

## Milestone 3 (More specifications: discounts, shipping cost based on ordered products weight, top-down approach)

## Milestone 4 (Multi-product catalog, arrays)

## Milestone 5 (Product names, customer info, order orinting, strings)

## Milestone 6 (Better memory usage, pointers)

## Milestone 7 (Better encapsulation, user-defined types)
- typedef {...} product_t;
- typedef {...} order_t;

## Milestone 8 (Order logging, files)
