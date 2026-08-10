-- Write your PostgreSQL query statement below
select department,employee,salary from (
select d.name as department,e.name as employee,e.salary,
dense_rank() over (partition by departmentid order by salary desc) as rank
from employee e left join department d
on e.departmentid = d.id) 
where rank <= 3;