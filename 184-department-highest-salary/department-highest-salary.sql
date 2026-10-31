with cte as (
    select e.salary as salary , e.name as name , d.name as dept from employee e
    join department d on e.departmentid=d.id
)
select department , employee , salary from (
    select cte.dept as department , cte.name as employee , cte.salary as salary,
    rank() over (partition by cte.dept order by salary desc) as rank
    from cte
) as x
where x.rank = 1;