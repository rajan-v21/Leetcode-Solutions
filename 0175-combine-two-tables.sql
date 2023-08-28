CREATE TABLE Person (personId INT, lastname VARCHAR(10), firstname VARCHAR(10));
INSERT INTO Person 
VALUES ROW(1, Wang, Allen), ROW(2, Alice, Bob);

CREATE TABLE Address (addressId INT, personId INT, city VARCHAR(10), state VARCHAR(10));
INSERT INTO Address 
VALUES ROW(1, 2, New York City, New York), ROW(2, 3, Leetcode, California);

SELECT firstname, lastname, city, state
FROM Person 
LEFT JOIN Address
ON Person.personId = Address.personId;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(n + m) SC: O(1) [for running query]

Intuition:

Simply ask question 'What we need?', 'From where we need?' & 'How can we retrieve it?'.
1. Using SELECT clause get the ids of the data we need.
2. Now using FROM & LEFT JOIN we determine which tables we need to join and retrieve data from.
(LEFT (OUTER) JOIN : Returns all records from the left table, and the matched records from the right table.)
3. And lastly, we retrieve data using ON clause providing a foreign key i.e a common id present in both tables.
------------------------------------------------------------------------------------------------------------------------------*/
