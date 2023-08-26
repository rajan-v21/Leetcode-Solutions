SELECT emp.name AS Employee
FROM Employee AS emp
JOIN Employee AS mgr
ON emp.managerId = mgr.id AND emp.salary > mgr.salary;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

Intuition:

Simply ask question 'What we need?', 'From where we need?' & 'How can we retrieve it?'.
1. Using SELECT clause get the ids of the data we need but in this question we have to return the name table with new id i.e
'Employee'.
2. Here we have intialized Employee table as emp and mgr separately to avoid confusion and treating same table as different.
3. Now using FROM & JOIN we determine which tables we need to join and retrieve data.
(JOIN : Returns records that have matching values in both tables.)
4. And lastly, we retrieve data using ON clause providing a pseudo foreign key i.e common id present in both tables with given
condition of question using AND clause.
------------------------------------------------------------------------------------------------------------------------------*/
