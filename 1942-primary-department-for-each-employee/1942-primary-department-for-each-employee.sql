# Write your MySQL query statement below
select employee_id ,department_id 
from employee 
where primary_flag = 'Y' or employee_id 
IN (select employee_id 
from employee
group by employee_id having count(distinct(department_id))=1
)