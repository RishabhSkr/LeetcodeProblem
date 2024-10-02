# Write your MySQL query statement below
SELECT a.id as Id
FROM Weather as a where exists (
    select b.id 
    from weather as b
    where DATEDIFF(a.recordDate,b.recordDate)=1 and a.temperature >b.temperature
)
