Table: Cinema

+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
seat_id is an auto-increment primary key column for this table.
Each row of this table indicates whether the ith seat is free or not. 1 means free while 0 means occupied.
 

Write an SQL query to report all the consecutive available seats in the cinema.

Return the result table ordered by seat_id in ascending order.

The test cases are generated so that more than two seats are consecutively available.

The query result format is in the following example.

 

Example 1:

Input: 
Cinema table:
+---------+------+
| seat_id | free |
+---------+------+
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
+---------+------+
Output: 
+---------+
| seat_id |
+---------+
| 3       |
| 4       |
| 5       |
+---------+

# Write your MySQL query statement below
select
    distinct(c1.seat_id)
from
    Cinema c1, Cinema c2
where
    c1.free = 1 and c1.free = c2.free and (c1.seat_id+1 = c2.seat_id or c1.seat_id-1 = c2.seat_id)


#250 ms solution
# Write your MySQL query statement below
select distinct a.seat_id
from cinema a
join cinema b
on abs(a.seat_id - b.seat_id) = 1
and a.free=true and b.free=true
order by a.seat_id;
