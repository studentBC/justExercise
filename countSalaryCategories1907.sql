# Write your MySQL query statement below
select 'Low Salary' as category, count(account_id) as accounts_count
from Accounts
where income < 20000


union

select 'Average Salary' as category, count(account_id) as accounts_count
from Accounts
where income >= 20000 and income <= 50000

union

select 'High Salary' as category, count(account_id) as accounts_count
from Accounts
where income > 50000

# 1474 ms solution
# Write your MySQL query statement below
WITH salary_summary AS (
    SELECT
        account_id,
        IF(income < 20000, "Low Salary", IF(income > 50000, "High Salary", "Average Salary")) as category
    FROM
        Accounts
)
SELECT
    category,
    COALESCE(accounts_count, 0) as accounts_count
FROM
    (SELECT "Low Salary" as category UNION SELECT "Average Salary" UNION SELECT "High Salary") master
    LEFT JOIN
    (SELECT count(account_id) as accounts_count, category FROM salary_summary GROUP BY category) tmp
    USING(category)
;
