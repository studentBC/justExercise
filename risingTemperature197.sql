# Write your MySQL query statement below
select 
    distinct(w2.id) 
from    
    Weather w1, Weather w2
where 
    DATE_SUB(w2.recordDate, INTERVAL 1 day) = w1.recordDate
    and w1.temperature < w2.temperature;

# 256 ms solution
select a.id
from weather a
inner join weather b
on TO_DAYS(a.recordDate) = TO_DAYS(b.recordDate) + 1
where a.temperature > b.temperature 
