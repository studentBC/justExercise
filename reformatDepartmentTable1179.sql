Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| revenue     | int     |
| month       | varchar |
+-------------+---------+
(id, month) is the primary key of this table.
The table has information about the revenue of each department per month.
The month has values in ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"].
 

Write an SQL query to reformat the table such that there is a department id column and a revenue column for each month.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Department table:
+------+---------+-------+
| id   | revenue | month |
+------+---------+-------+
| 1    | 8000    | Jan   |
| 2    | 9000    | Jan   |
| 3    | 10000   | Feb   |
| 1    | 7000    | Feb   |
| 1    | 6000    | Mar   |
+------+---------+-------+
Output: 
+------+-------------+-------------+-------------+-----+-------------+
| id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
+------+-------------+-------------+-------------+-----+-------------+
| 1    | 8000        | 7000        | 6000        | ... | null        |
| 2    | 9000        | null        | null        | ... | null        |
| 3    | null        | 10000       | null        | ... | null        |
+------+-------------+-------------+-------------+-----+-------------+
Explanation: The revenue from Apr to Dec is null.
Note that the result table has 13 columns (1 for the department id + 12 for the months).


select id, 
	sum(case when month = 'jan' then revenue else null end) as Jan_Revenue,
	sum(case when month = 'feb' then revenue else null end) as Feb_Revenue,
	sum(case when month = 'mar' then revenue else null end) as Mar_Revenue,
	sum(case when month = 'apr' then revenue else null end) as Apr_Revenue,
	sum(case when month = 'may' then revenue else null end) as May_Revenue,
	sum(case when month = 'jun' then revenue else null end) as Jun_Revenue,
	sum(case when month = 'jul' then revenue else null end) as Jul_Revenue,
	sum(case when month = 'aug' then revenue else null end) as Aug_Revenue,
	sum(case when month = 'sep' then revenue else null end) as Sep_Revenue,
	sum(case when month = 'oct' then revenue else null end) as Oct_Revenue,
	sum(case when month = 'nov' then revenue else null end) as Nov_Revenue,
	sum(case when month = 'dec' then revenue else null end) as Dec_Revenue
from department
group by id



# Write your MySQL query statement below
#374 ms solution
SELECT id,
MIN(CASE WHEN month = 'Jan' THEN revenue END) AS Jan_Revenue,
MIN(CASE WHEN month = 'Feb' THEN revenue END) AS Feb_Revenue,
MIN(CASE WHEN month = 'Mar' THEN revenue END) AS Mar_Revenue,
MIN(CASE WHEN month = 'Apr' THEN revenue END) AS Apr_Revenue,
MIN(CASE WHEN month = 'May' THEN revenue END) AS May_Revenue,
MIN(CASE WHEN month = 'Jun' THEN revenue END) AS Jun_Revenue,
MIN(CASE WHEN month = 'Jul' THEN revenue END) AS Jul_Revenue,
MIN(CASE WHEN month = 'Aug' THEN revenue END) AS Aug_Revenue,
MIN(CASE WHEN month = 'Sep' THEN revenue END) AS Sep_Revenue,
MIN(CASE WHEN month = 'Oct' THEN revenue END) AS Oct_Revenue,
MIN(CASE WHEN month = 'Nov' THEN revenue END) AS Nov_Revenue,
MIN(CASE WHEN month = 'Dec' THEN revenue END) AS Dec_Revenue

FROM Department
GROUP BY Id
