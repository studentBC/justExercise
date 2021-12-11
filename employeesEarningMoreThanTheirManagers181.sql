# Write your MySQL query statement below
select name as 'Employee' from Employee ee where ee.salary > ( select salary from Employee where Employee.id = ee.managerId)


# 264 ms solution
select e.name as Employee from Employee e join Employee m on e.managerId=m.id and e.salary > m.salary;
