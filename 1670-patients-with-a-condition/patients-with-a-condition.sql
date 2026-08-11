-- Write your PostgreSQL query statement below
select *
from patients
where conditions ~'^DIAB1' or conditions ~' DIAB1';