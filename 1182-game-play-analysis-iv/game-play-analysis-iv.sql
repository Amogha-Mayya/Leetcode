-- Write your PostgreSQL query statement below
select round(count(distinct player_id)::numeric/(select count(distinct player_id) as counter 
from activity),2) as fraction from 
(SELECT *,
           MIN(event_date) OVER (
               PARTITION BY player_id
           ) AS first_date
    FROM activity) as x
where x.event_date = interval '1 days' + x.first_date;