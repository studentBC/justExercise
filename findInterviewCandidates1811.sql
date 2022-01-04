+--------------+------+
| Column Name  | Type |
+--------------+------+
| contest_id   | int  |
| gold_medal   | int  |
| silver_medal | int  |
| bronze_medal | int  |
+--------------+------+
contest_id is the primary key for this table.
This table contains the LeetCode contest ID and the user IDs of the gold, silver, and bronze medalists.
It is guaranteed that any consecutive contests have consecutive IDs and that no ID is skipped.
 

Table: Users

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| mail        | varchar |
| name        | varchar |
+-------------+---------+
user_id is the primary key for this table.
This table contains information about the users.
 

Write an SQL query to report the name and the mail of all interview candidates. A user is an interview candidate if at least one of these two conditions is true:

The user won any medal in three or more consecutive contests.
The user won the gold medal in three or more different contests (not necessarily consecutive).
Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Contests table:
+------------+------------+--------------+--------------+
| contest_id | gold_medal | silver_medal | bronze_medal |
+------------+------------+--------------+--------------+
| 190        | 1          | 5            | 2            |
| 191        | 2          | 3            | 5            |
| 192        | 5          | 2            | 3            |
| 193        | 1          | 3            | 5            |
| 194        | 4          | 5            | 2            |
| 195        | 4          | 2            | 1            |
| 196        | 1          | 5            | 2            |
+------------+------------+--------------+--------------+
Users table:
+---------+--------------------+-------+
| user_id | mail               | name  |
+---------+--------------------+-------+
| 1       | sarah@leetcode.com | Sarah |
| 2       | bob@leetcode.com   | Bob   |
| 3       | alice@leetcode.com | Alice |
| 4       | hercy@leetcode.com | Hercy |
| 5       | quarz@leetcode.com | Quarz |
+---------+--------------------+-------+
Output: 
+-------+--------------------+
| name  | mail               |
+-------+--------------------+
| Sarah | sarah@leetcode.com |
| Bob   | bob@leetcode.com   |
| Alice | alice@leetcode.com |
| Quarz | quarz@leetcode.com |
+-------+--------------------+
Explanation: 
Sarah won 3 gold medals (190, 193, and 196), so we include her in the result table.
Bob won a medal in 3 consecutive contests (190, 191, and 192), so we include him in the result table.
    - Note that he also won a medal in 3 other consecutive contests (194, 195, and 196).
Alice won a medal in 3 consecutive contests (191, 192, and 193), so we include her in the result table.
Quarz won a medal in 5 consecutive contests (190, 191, 192, 193, and 194), so we include them in the result table.
 

Follow up:

What if the first condition changed to be "any medal in n or more consecutive contests"? How would you change your solution to get the interview candidates? Imagine that n is the parameter of a stored procedure.
Some users may not participate in every contest but still perform well in the ones they do. How would you change your solution to only consider contests where the user was a participant? Suppose the registered users for each contest are given in another table.


# Write your MySQL query statement below
select name, mail
from Users
where user_id in (
    select gold_medal
    from Contests
    group by gold_medal
    having count(gold_medal) > 2
) or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.silver_medal and b.silver_medal = c.bronze_medal )
) or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.bronze_medal and b.bronze_medal = c.silver_medal)
) or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.gold_medal and b.gold_medal = c.silver_medal)
)or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.silver_medal and b.silver_medal = c.gold_medal)
)or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.bronze_medal and b.bronze_medal = c.gold_medal)
)or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.silver_medal and b.silver_medal = c.gold_medal     )
)or  user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.gold_medal and b.gold_medal = c.gold_medal)
) or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.gold_medal and b.gold_medal = c.bronze_medal)
) or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.bronze_medal and b.bronze_medal = c.gold_medal  )
)  or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.gold_medal and b.gold_medal = c.gold_medal   )
) or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.gold_medal and b.gold_medal = c.silver_medal)
) or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.silver_medal and b.silver_medal = c.silver_medal)
) or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.silver_medal and b.silver_medal = c.gold_medal            ) )or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.gold_medal and b.gold_medal = c.silver_medal )
)or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.silver_medal and b.silver_medal = c.silver_medal          )
)or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.silver_medal and b.silver_medal = c.bronze_medal       )     )or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.bronze_medal and b.bronze_medal = c.silver_medal      )     )or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.silver_medal and b.silver_medal = c.silver_medal     )         )or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.bronze_medal and b.bronze_medal = c.bronze_medal    )
)or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.bronze_medal and b.bronze_medal = c.gold_medal     )           )or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.gold_medal and b.gold_medal = c.bronze_medal      )           )or user_id in (
    select a.gold_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.gold_medal = b.bronze_medal and b.bronze_medal = c.bronze_medal   )             )or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.bronze_medal and b.bronze_medal = c.silver_medal)             )or user_id in (
    select a.bronze_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.bronze_medal = b.silver_medal and b.silver_medal = c.bronze_medal  )           )or user_id in (
    select a.silver_medal
    from Contests a, Contests b, Contests c
    where (a.contest_id+1 = b.contest_id and
        b.contest_id+1 = c.contest_id) and
    (a.silver_medal = b.bronze_medal and b.bronze_medal = c.bronze_medal )
)


#764 ms solution
# Write your MySQL query statement below
with cont as (
select contest_id, gold_medal as user_id
    from contests
union all
select contest_id, silver_medal as user_id
       from contests
union all
select contest_id,bronze_medal as user_id
   from contests),
any_3 as (
select c1.contest_id, c1.user_id as user_id
from cont c1
join cont c2
on c1.user_id=c2.user_id and (c2.contest_id -c1.contest_id) between 1 and 2
    group by 1 ,2
having count(*) =2
 ),
ans as (
select user_id
from any_3
union
select gold_medal
from contests
    group by 1
having count(*) >=3)
select name,mail
from users  u
join ans a
on u.user_id = a.user_id
