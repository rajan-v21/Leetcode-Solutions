CREATE TABLE Employee (id INT, name VARCHAR(10), salary INT, managerId INT);
INSERT INTO Employee 
VALUES ROW(1, Joe, 70000, 3), ROW(2, Henry, 80000, 4), ROW(3, Sam, 60000, Null), ROW(4, Max, 90000, Null);

SELECT emp.name AS Employee
FROM Employee AS emp
JOIN Employee AS mgr
ON emp.managerId = mgr.id AND emp.salary > mgr.salary;

/*-----------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1) [for running query]

Intuition:

Simply ask question 'What we need?', 'From where we need?' & 'How can we retrieve it?'.
1. Using SELECT clause get the ids of the data we need but in this question we have to return the 'name' id of the table as 
'Employee'.
2. Here we have intialized Employee table as emp and mgr separately to avoid confusion and treating the same table as 
different entities.
3. Now using FROM & JOIN we determine which tables we need to join and retrieve data.
(JOIN : Returns records that have matching values in both tables.)
4. And lastly, we retrieve data using ON clause providing a pseudo foreign key i.e a common id present in both the tables with 
given condition of the question using AND clause.
-----------------------------------------------------------------------------------------------------------------------------*/
