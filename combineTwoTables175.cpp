# Write your MySQL query statement below
select firstName, lastName, city, state 
from Person 
left join Address
on Person.personId=Address.personId;

#268 ms solution
SELECT firstName, lastName, city, state FROM Address RIGHT JOIN Person  ON
Person.PersonID = Address.PersonID;
