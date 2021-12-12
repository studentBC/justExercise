# Write your MySQL query statement below
select email as Email from Person
group by email
having count(id) > 1;

#244 ms solution
# Write your MySQL query statement below
select email from Person group by email having count(*) > 1;
