Table: Point

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
+-------------+------+
x is the primary key column for this table.
Each row of this table indicates the position of a point on the X-axis.
 

Write an SQL query to report the shortest distance between any two points from the Point table.

The query result format is in the following example.

 

Example 1:

Input: 
Point table:
+----+
| x  |
+----+
| -1 |
| 0  |
| 2  |
+----+
Output: 
+----------+
| shortest |
+----------+
| 1        |
+----------+
Explanation: The shortest distance is between points -1 and 0 which is |(-1) - 0| = 1.
 

Follow up: How could you optimize your query if the Point table is ordered in ascending order?

# Write your MySQL query statement below
select min(abs(a.x - b.x)) as shortest
from Point a, Point b
where a.x != b.x
order by abs(a.x - b.x) limit 1


# Write your MySQL query statement below
SELECT min(distance) as shortest from
(
SELECT x, abs(x- LEAD(x) OVER(order by x asc)) as distance from point
) x
