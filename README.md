# XCommerce Standalone - C
This is the telecommerce application, developed in C programming language. It is used by a call center operator on behalf of calling customers.

## ILOs
1. Recognize the importance of computer programming in modern society
2. Apply the algorithmic thinking and approach in problem-solving, and be able to express algorithms using pseudo code and flow charts
3. Apply C data types, expressions, selections and repetitions, in order to translate algorithms to programs
4. Apply the process of writing, compiling, debugging and testing C programs using a modern IDE (currently VS Code), as well as sharing them through a version control system (currently Git)
5. Apply the top-down/divide-and-conquer approach for more advanced problems, in order to break them down into simpler sub-problems, while focusing on the high-level solution
6. Identify C header and source files required by a program, and be able to organize it accordingly, in order to promote modularity
7. Apply various features of C programming including pointers, arrays and strings, and ultimately user-defined data types and files
8. Explain the purpose of a C program that is written by others, and analyze whether it compiles and runs successfully
9. Be aware of the different aspects related to ethics in computer science and demonstrate that they are able to adhere to them according to different situations

It is part of the overarching [XCommerce](https://github.com/oiraqi/xcommerce) project. Other sibiling sub-projects are:
- [XCommerce Standalone (C)](https://github.com/oiraqi/xcommerce-standalone-c)
- [XCommerce Cloud Microservices (Spring Cloud)](https://github.com/oiraqi/xcommerce-microservices)
- [XCommerce PWA (Angular)](https://github.com/oiraqi/xcommerce-client-angular)

**You're welcome to contrbute through your favourite monolithic or microservices back-end technology and/or front-end technology!**

**The *progress* folder**: In every semester, the author rewrites the code with his students. The *progress* folder reflects where they are now. It is reinitialized in the beginning of each Fall (September 1st) and Spring (January 1st).

**Starting point**
- Clone this repository
- Depending on the stage you would like to work on, cd [ *initial* | *progress* | *final* ]
- ./gradlew build
- There you go!

**You need to install Docker, then run these commands**
- docker pull redis
- docker pull postgres
- docker run --name redis-container -p 6379:6379 -d redis
- docker run --name postgres-container -e POSTGRES_PASSWORD=postgres -p 5432:5432 -d postgres
- docker exec -it postgres-container psql -U postgres
- create database xcommerce
