-- Write your PostgreSQL query statement below
select user_id,round(total::numeric/counter,2) as confirmation_rate from 
(select s.user_id as user_id,count(*) as counter,
sum(case when action = 'confirmed' then 1
else 0 end) as total
from signups s left join confirmations c
on s.user_id = c.user_id
group by s.user_id);