# Write your MySQL query statement below
select s.product_id,s.year first_year,s.quantity,s.price
from sales s 
where  (product_id,year) in (select product_id,min(year) from sales group by product_id)