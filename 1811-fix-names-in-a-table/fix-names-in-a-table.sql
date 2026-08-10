-- Write your PostgreSQL query statement below
select user_id,concat(substring(upper(name),1,1),substring(lower(name),2,length(name)-1)) as name
from users
order by user_id;