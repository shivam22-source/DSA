# Write your MySQL query statement below
select distinct class 
from Courses

where (class) in(
select class
from Courses
group by class
having count(distinct student)>=5
);



