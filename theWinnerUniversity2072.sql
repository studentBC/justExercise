# Write your MySQL query statement below
select 
(CASE
    WHEN (select count(student_id) from NewYork where score >= 90) > (select count(student_id) from California where score >= 90) THEN 'New York University'
    WHEN (select count(student_id) from NewYork where score >= 90 ) < (select count(student_id) from California where score >= 90) THEN 'California University'
    ELSE 'No Winner'
END) as winner

# Write your MySQL query statement below
select 
case
    when (select count(student_id) from NewYork where score > 89) > (select count(student_id) from California where score > 89) then 'New York University'
    when (select count(student_id) from NewYork where score > 89) < (select count(student_id) from California where score > 89) then 'California University'
    else 'No Winner'
end
as winner




# SELECT (CASE 
#             WHEN (SELECT COUNT(score) FROM NewYork WHERE score >= 90) > (SELECT COUNT(score) FROM California WHERE score >= 90) THEN 'New York University'
#             WHEN (SELECT COUNT(score) FROM NewYork WHERE score >= 90) < (SELECT COUNT(score) FROM California WHERE score >= 90) THEN 'California University'
#             ELSE 'No Winner' END) AS WINNER
# ;
