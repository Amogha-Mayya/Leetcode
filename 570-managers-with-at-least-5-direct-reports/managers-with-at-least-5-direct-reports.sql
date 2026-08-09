-- Write your PostgreSQL query statement below
select name from (select a.id,a.name as name
from employee a join employee b
on a.id = b.managerid
group by a.id,a.name
having count(*) >= 5);