# Write your MySQL query statement below
with temp as (
    select player_id,min(event_date) as first_login
    from activity 
    group by player_id
)

select 
    round(sum(datediff(a.event_date,t.first_login)=1)/count(distinct(a.player_id))
    ,2) as fraction
from activity as a
join temp as t on a.player_id =t.player_id;