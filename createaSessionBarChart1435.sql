Table: Sessions

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| session_id          | int     |
| duration            | int     |
+---------------------+---------+
session_id is the primary key for this table.
duration is the time in seconds that a user has visited the application.
 

You want to know how long a user visits your application. You decided to create bins of "[0-5>", "[5-10>", "[10-15>", and "15 minutes or more" and count the number of sessions on it.

Write an SQL query to report the (bin, total).

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Sessions table:
+-------------+---------------+
| session_id  | duration      |
+-------------+---------------+
| 1           | 30            |
| 2           | 199           |
| 3           | 299           |
| 4           | 580           |
| 5           | 1000          |
+-------------+---------------+
Output: 
+--------------+--------------+
| bin          | total        |
+--------------+--------------+
| [0-5>        | 3            |
| [5-10>       | 1            |
| [10-15>      | 0            |
| 15 or more   | 1            |
+--------------+--------------+
Explanation: 
For session_id 1, 2, and 3 have a duration greater or equal than 0 minutes and less than 5 minutes.
For session_id 4 has a duration greater or equal than 5 minutes and less than 10 minutes.
There is no session with a duration greater than or equal to 10 minutes and less than 15 minutes.
For session_id 5 has a duration greater than or equal to 15 minutes.

# Write your MySQL query statement below
select '[0-5>' as bin , count(*) as total
from Sessions
where duration < 300

union

select '[5-10>' as bin , count(*) as total
from Sessions
where duration >= 300 and duration < 600

union

select '[10-15>' as bin , count(*) as total
from Sessions
where duration >= 600 and duration < 900

union

select '15 or more' as bin , count(*) as total
from Sessions
where duration >= 900


#293 ms solution
# Write your MySQL query statement below
SELECT '[0-5>' AS 'bin', SUM(duration/60 < 5) AS 'total'
FROM Sessions
UNION
SELECT '[5-10>' AS 'bin', SUM(duration/60 >= 5 AND duration/60 < 10) AS 'total'
FROM Sessions
UNION
SELECT '[10-15>' AS 'bin', SUM(duration/60 >= 10 AND duration/60 < 15) AS 'total'
FROM Sessions
UNION
SELECT '15 or more' AS 'bin', SUM(duration/60 >= 15) AS 'total'
FROM Sessions
