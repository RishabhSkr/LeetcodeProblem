# Write your MySQL query statement below
select x,y,z,case when x+y>z AND y+z>x AND z+x >y  then 'Yes' else 'No' end as triangle
from triangle