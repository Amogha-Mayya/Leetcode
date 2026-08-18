-- Write your PostgreSQL query statement below
select max(salary) as secondhighestsalary from (select salary,
dense_rank() over (order by salary desc) as rank
from employee) where rank = 2;