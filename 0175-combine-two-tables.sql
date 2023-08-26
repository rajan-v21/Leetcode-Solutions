SELECT firstname, lastname, city, state
FROM Person 
LEFT JOIN Address
ON Person.personId = Address.personId;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(n + m) SC: O(1)

Intuition:

Simply ask question 'What we need?', 'From where we need?' & 'How can we retrieve it?'.
1. Using SELECT clause get the ids of the data we need.
2. Now using FROM & LEFT JOIN we determine which tables we need to join and retrieve data from.
(LEFT (OUTER) JOIN : Returns all records from the left table, and the matched records from the right table.)
3. And lastly, we retrieve data using ON clause providing a foreign key i.e a common id present in both tables.
------------------------------------------------------------------------------------------------------------------------------*/
