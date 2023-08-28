CREATE TABLE Person (id INT, email VARCHAR(20));
INSERT INTO Person 
VALUES ROW(1, a@b.com), ROW(2, c@d.com), ROW(3, a@b.com);

SELECT Email
From Person
GROUP BY email
HAVING COUNT(*) > 1;

/*--------------------------------------------------------------------------------------------------------------------------------
TC: O(nlog(n)) SC: O(1) [for running query]

Intuition:

1. Simply select the emails from person table and then group the emails alphabetically which are occuring more than once.
--------------------------------------------------------------------------------------------------------------------------------*/
