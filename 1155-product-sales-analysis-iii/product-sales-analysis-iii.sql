-- Write your PostgreSQL query statement below
select product_id,year as first_year,quantity,price from (select *,
rank() over (partition by product_id order by year) as rank
from sales)
where rank = 1;