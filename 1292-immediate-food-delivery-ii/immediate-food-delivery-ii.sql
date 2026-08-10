-- Write your PostgreSQL query statement below
select round(count(*)::numeric/(select count(distinct customer_id) from delivery)*100,2) as immediate_percentage from (select *,
rank() over (partition by customer_id order by order_date) as rank
from delivery) as x
where x.rank = 1 and x.order_date = x.customer_pref_delivery_date;