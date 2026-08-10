-- Write your PostgreSQL query statement below
with cte as (select num
from mynumbers 
group by num
having count(num) = 1
order by num desc limit 1)

select max(num) as num from cte;