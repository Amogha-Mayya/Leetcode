-- Write your PostgreSQL query statement below
with cte as (select *,
rank() over (partition by employee_id order by primary_flag desc)
from employee)

select employee_id,department_id from cte where rank = 1;
