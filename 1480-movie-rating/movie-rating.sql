-- Write your PostgreSQL query statement below
with cte as (
    select name,count(*) as cnt from movierating m left join 
    users u on m.user_id = u.user_id
    group by name order by cnt desc,name asc limit 1
),
cte2 as (
    select title,avg(rating) as avg from movierating m left join movies m2
    on m.movie_id = m2.movie_id where created_at between '2020-02-01' and '2020-02-29'
    group by title order by avg desc,title limit 1
)
select name as results from cte as results
UNION ALL
select title from cte2;