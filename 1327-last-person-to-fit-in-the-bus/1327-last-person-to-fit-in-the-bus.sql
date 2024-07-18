# Write your MySQL query statement below
with p1 as (
    SELECT person_name,turn,sum(weight) over (order by turn ) as sm 
    from queue q1
)
SELECT 
    p1.person_name from p1
where sm<=1000 
ORDER BY turn DESC
LIMIT 1;

