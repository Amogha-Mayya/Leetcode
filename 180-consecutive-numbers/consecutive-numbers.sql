-- Write your PostgreSQL query statement below
select distinct num as ConsecutiveNums from ( select *,
lead(num) over (order by id) as lead1,
lead(num,2) over (order by id) as lead2
from logs) as x
where x.num = x.lead1 and x.lead1 = x.lead2;