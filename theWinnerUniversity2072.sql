# Write your MySQL query statement below
select 
(CASE
    WHEN (select count(student_id) from NewYork where score >= 90) > (select count(student_id) from California where score >= 90) THEN 'New York University'
    WHEN (select count(student_id) from NewYork where score >= 90 ) < (select count(student_id) from California where score >= 90) THEN 'California University'
    ELSE 'No Winner'
END) as winner


