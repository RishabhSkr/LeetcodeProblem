# Write your MySQL query statement below
SELECT p.project_id,ROUND(AVG(e.experience_years),2) as average_years
FROM Employee as e
JOIN Project as p using (employee_id)
group by p.project_id
