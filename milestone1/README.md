# Milestone 1: Basic Specifications / Algorithms Only
## 1.1
We start by considering a **single-product** catalog. Each customer calls and specifies the quantity of the product (the only one available) s/he wants to order. The operator shall use the Telecommerce Application to compute the total price.
- Identify the problem input and output
- Design the algorithm and express it as a flow chart
### First alternative (Product price is an input)
<p align="center">
  <img src="images/TCA_1_1_a.png">
</p>

### Second alternative (Product price is a constant)
<p align="center">
  <img src="images/TCA_1_1_b.png">
</p>

## 1.2
In addition to the total price, the operator needs to compute the VAT too (20%)
- Update the problem input and output
- Enhance your algorithm and corresponding flow chart
<p align="center">
  <img src="images/TCA_1_2.png">
</p>

## 1.3
We add now a **constraint**. When the customer calls and specifies the quantity to order, the Telecommerce Application shall check first the availability of the product, compute the total price and VAT if and only if the ordered quantiy is available, or give an error message otherwise ("Ordered quantity unavailable").
- Enhance your algorithm and corresponding flow chart
<p align="center">
  <img src="images/TCA_1_3.png">
</p>

## 1.4
We consider now a **three-produc**t catalog. Each product has its own price. A customer can call and specify one (and only one) product to order, along with the desired quantity. The operator shall use the Telecommerce Application to compute the total price, as well as the VAT if and only if the ordered quantity of the selected product is available, or give an error message otherwise ("Ordered quantity uavailable").
- Identify the problem input and output
- Design the algorithm and express it as a flow chart
<p align="center">
  <img src="images/TCA_1_4.png">
</p>

## 1.5
We still consider a three-product catalog. However, a customer may call and specify one or more products to order, along with their respective quantities. The customer can specify the same product many times, e.g. 3 x Product1, then 2 x Product2, then 1 x Product1.
- Enhance your algorithm and corresponding flow chart
<p align="center">
  <img src="images/TCA_1_5.png">
</p>
