CREATE TABLE Person (id INT, email VARCHAR(20));
INSERT INTO Person 
VALUES ROW(1, john@example.com), ROW(2, bob@example.com), ROW(3, john@example.com);

DELETE p1 
FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.id > p2.id;

/*-------------------------------------------------------------------------------------------------------------------------------
TC: O(n^2) SC: O(1) [for running query]

Intuition: 

1. Intuition is to match each mail with every other mail which is below it in table i.e the entry whose id value is greater than
current entry.
2. For this we create to two identifiers p1 and p2 separately to avoid confusion and treating the same table as 
different entities.
3. Now we just compare p1's email to every other email below it i.e p2's email.
-------------------------------------------------------------------------------------------------------------------------------*/
