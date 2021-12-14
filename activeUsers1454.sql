Table: Accounts

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key for this table.
This table contains the account id and the user name of each account.
 

Table: Logins

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| login_date    | date    |
+---------------+---------+
There is no primary key for this table, it may contain duplicates.
This table contains the account id of the user who logged in and the login date. A user may log in multiple times in the day.
 

Active users are those who logged in to their accounts for five or more consecutive days.

Write an SQL query to find the id and the name of active users.

Return the result table ordered by id.

The query result format is in the following example.

 

Example 1:

Input: 
Accounts table:
+----+----------+
| id | name     |
+----+----------+
| 1  | Winston  |
| 7  | Jonathan |
+----+----------+
Logins table:
+----+------------+
| id | login_date |
+----+------------+
| 7  | 2020-05-30 |
| 1  | 2020-05-30 |
| 7  | 2020-05-31 |
| 7  | 2020-06-01 |
| 7  | 2020-06-02 |
| 7  | 2020-06-02 |
| 7  | 2020-06-03 |
| 1  | 2020-06-07 |
| 7  | 2020-06-10 |
+----+------------+
Output: 
+----+----------+
| id | name     |
+----+----------+
| 7  | Jonathan |
+----+----------+
Explanation: 
User Winston with id = 1 logged in 2 times only in 2 different days, so, Winston is not an active user.
User Jonathan with id = 7 logged in 7 times in 6 different days, five of them were consecutive days, so, Jonathan is an active user.
 

Follow up: Could you write a general solution if the active users are those who logged in to their accounts for n or more consecutive days?

# Write your MySQL query statement below
select Accounts.id, Accounts.name
from Accounts
where Accounts.id in (
    select a.id
    from Logins a, Logins b, Logins c, Logins d, Logins e  
    where a.id = b.id and b.id = c.id and c.id = d.id and d.id = e.id and
    DATE_SUB(a.login_date, INTERVAL 1 DAY) = b.login_date and 
    DATE_SUB(b.login_date, INTERVAL 1 DAY) = c.login_date and
    DATE_SUB(c.login_date, INTERVAL 1 DAY) = d.login_date and
    DATE_SUB(d.login_date, INTERVAL 1 DAY) = e.login_date 
    
    group by a.id, a.login_date
)
order by Accounts.id

#925 ms solution
# Write your MySQL query statement below

select distinct d.id, a.name from

(select id, login_date, date_add(login_date, interval -row_number()
                                 over(partition by id order by login_date) day) as grouped_date from Logins GROUP BY 1,2) d

left join Accounts a
on d.id = a.id
group by id, grouped_date
having count(grouped_date) >= 5
order by d.id;
