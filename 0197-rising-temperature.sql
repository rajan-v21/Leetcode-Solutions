CREATE TABLE Weather (id INT, recordDate DATE, temperature INT);
INSERT INTO Weather 
VALUES ROW(1, 2015-01-01, 10), ROW(2, 2015-01-02, 25), ROW(3, 2015-01-03, 20), ROW(4, 2015-01-04, 30);

SELECT w1.id
FROM Weather AS w1, Weather AS w2
wHERE w1.temperature > w2.temperature 
AND DATEDIFF(w1.recordDate , w2.recordDate) = 1;

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1) [for running query]

Intuition:

1. Simply compare tempature of first record with second to find which is greater keeping in mind the diffrence between the dates
is no more than 1.
------------------------------------------------------------------------------------------------------------------------------*/
