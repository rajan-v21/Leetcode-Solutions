CREATE TABLE Customers (id INT, name VARCHAR(10));
INSERT INTO Customers 
VALUES ROW(1, Joe), ROW(2, Henry), ROW(3, Sam), ROW(4, Max);

CREATE TABLE Orders (id INT, customerId INT);
INSERT INTO Orders 
VALUES ROW(1, 3),ROW(2, 1);

SELECT name AS Customers
FROM Customers
LEFT JOIN Orders
ON Orders.customerId = Customers.id
WHERE Orders.customerId IS NULL;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1) [for running query]

Intuition:

1. We need names of all the customers who never ordered anything and print result under 'Customer' column.
2. So we select name of all the customers as customers from customer table and perform left join with Orders table.
(LEFT (OUTER) JOIN : Returns all records from the left table, and the matched records from the right table.)
3. And lastly, we retrieve data using ON clause providing a pseudo foreign key i.e a common id present in both the tables with 
given condition using WHERE clause.
4. Remember when we are using left join it joins customerId of orders table to its respective cutomer's id and as not all 
customers are not ordering, some customer's customerId will be null. And those are the customers we want.
    For eg: +------+--------+--------------+
            |  id  |  name  |  customerId  |
            +------+--------+--------------+
            |  1   |  Joe   |      1       |
            +------+--------+--------------+
            |  2   |  Henry |     NULL     |
            +------+--------+--------------+
            |  3   |  Sam   |      3       |
            +------+--------+--------------+
            |  4   |  Max   |     NULL     |
            +------+--------+--------------+
------------------------------------------------------------------------------------------------------------------------------*/
