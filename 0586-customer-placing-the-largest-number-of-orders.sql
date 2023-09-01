CREATE TABLE Orders (order_number INT, customer_number INT)
INSERT INTO Orders
VALUE ROW(1, 1), ROW(2, 2), ROW(3, 3), ROW(4, 3);

SELECT customer_number 
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) 
DESC LIMIT 1;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(nlog(n)) SC: O(1) [for running query]

Intuition:

1. First, we will re-group and sort the customer_number column in desceding order by using GROUP BY, ORDER BY and DESC clause 
respectively by counting the frequency of a customer's purchase using COUNT clause.
2. After that, as we want customer who ordered most, use the LIMTI clause and set it to 1 to get the top most 1st customer.
------------------------------------------------------------------------------------------------------------------------------*/
