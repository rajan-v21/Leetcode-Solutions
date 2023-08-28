SELECT Email
From Person
GROUP BY email
HAVING COUNT(*) > 1;

/*--------------------------------------------------------------------------------------------------------------------------------
TC: O(nlog(n)) SC: O(1)

Intuition:

1. Simply select the emails from person table and then group the emails alphabetically which are having count more than 1.
--------------------------------------------------------------------------------------------------------------------------------*/
