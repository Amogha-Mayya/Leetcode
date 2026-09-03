-- Write your PostgreSQL query statement below
select id from (select *,
lag(recordDate) over (order by recordDate) as lag_date,
lag(temperature) over (order by recordDate) as lag_temp
from weather)
where temperature > lag_temp and recorddate = interval '1 days' + lag_date;