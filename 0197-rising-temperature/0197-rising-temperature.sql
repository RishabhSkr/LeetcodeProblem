# Write your MySQL query statement below
SELECT a.id 
FROM Weather as a
JOIN Weather as b
ON DATEDIFF(a.recordDate,b.recordDate)=1
WHERE a.temperature>b.temperature
