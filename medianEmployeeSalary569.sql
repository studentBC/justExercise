Table: Employee

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| company      | varchar |
| salary       | int     |
+--------------+---------+
id is the primary key column for this table.
Each row of this table indicates the company and the salary of one employee.
 

Write an SQL query to find the median salary of each company.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Employee table:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 1  | A       | 2341   |
| 2  | A       | 341    |
| 3  | A       | 15     |
| 4  | A       | 15314  |
| 5  | A       | 451    |
| 6  | A       | 513    |
| 7  | B       | 15     |
| 8  | B       | 13     |
| 9  | B       | 1154   |
| 10 | B       | 1345   |
| 11 | B       | 1221   |
| 12 | B       | 234    |
| 13 | C       | 2345   |
| 14 | C       | 2645   |
| 15 | C       | 2645   |
| 16 | C       | 2652   |
| 17 | C       | 65     |
+----+---------+--------+
Output: 
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 5  | A       | 451    |
| 6  | A       | 513    |
| 12 | B       | 234    |
| 9  | B       | 1154   |
| 14 | C       | 2645   |
+----+---------+--------+


SELECT Id, Company, Salary
FROM (
SELECT *, ROW_NUMBER() OVER(PARTITION BY COMPANY ORDER BY Salary ASC, Id ASC) AS RN_ASC,
ROW_NUMBER() OVER(PARTITION BY COMPANY ORDER BY Salary DESC, Id DESC) AS RN_DESC
FROM Employee) AS temp
WHERE RN_ASC BETWEEN RN_DESC - 1 AND RN_DESC + 1
ORDER BY Company, Salary;


# the explaination
WITH cte AS (
    SELECT
        *,
        ROW_NUMBER() OVER(PARTITION BY COMPANY ORDER BY Salary ASC, Id ASC) AS RN_ASC,
        ROW_NUMBER() OVER(PARTITION BY COMPANY ORDER BY Salary DESC, Id DESC) AS RN_DESC
    FROM Employee
)
SELECT *, ABS(CAST(RN_ASC AS SIGNED) - CAST(RN_DESC AS SIGNED)) FROM cte;
;
/*
+------+---------+--------+--------+---------+-------------------------------------------------------+
| Id   | Company | Salary | RN_ASC | RN_DESC | ABS(CAST(RN_ASC AS SIGNED) - CAST(RN_DESC AS SIGNED)) |
+------+---------+--------+--------+---------+-------------------------------------------------------+
|    4 | A       |  15314 |      6 |       1 |                                                     5 |
|    1 | A       |   2341 |      5 |       2 |                                                     3 |
|    6 | A       |    513 |      4 |       3 |                                                     1 |
|    5 | A       |    451 |      3 |       4 |                                                     1 |
|    2 | A       |    341 |      2 |       5 |                                                     3 |
|    3 | A       |     15 |      1 |       6 |                                                     5 |
|   10 | B       |   1345 |      6 |       1 |                                                     5 |
|   11 | B       |   1221 |      5 |       2 |                                                     3 |
|    9 | B       |   1154 |      4 |       3 |                                                     1 |
|   12 | B       |    234 |      3 |       4 |                                                     1 |
|    7 | B       |     15 |      2 |       5 |                                                     3 |
|    8 | B       |     13 |      1 |       6 |                                                     5 |
|   16 | C       |   2652 |      5 |       1 |                                                     4 |
|   15 | C       |   2645 |      4 |       2 |                                                     2 |
|   14 | C       |   2645 |      3 |       3 |                                                     0 |
|   13 | C       |   2345 |      2 |       4 |                                                     2 |
|   17 | C       |     65 |      1 |       5 |                                                     4 |
+------+---------+--------+--------+---------+-------------------------------------------------------+
*/
