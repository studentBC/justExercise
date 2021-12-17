Table: Seat

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the name and the ID of a student.
id is a continuous increment.
 

Write an SQL query to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by id in ascending order.

The query result format is in the following example.

 

Example 1:

Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.

# Write your MySQL query statement below
select s1.id, s2.student
from Seat s1, Seat s2
where (s1.id%2 = 1 and s2.id = s1.id+1 or s1.id%2 = 0 and s2.id = s1.id-1 or (select max(id) from Seat)%2 = 1 and s1.id = (select max(id) from Seat) and s1.id = s2.id)
order by id

#208 ms solution
SELECT rank()
over(
    ORDER BY IF( id%2=0 , id-1 , id+1 )
) as id, student
FROM Seat 
