# Write your MySQL query statement below
-- LAG AND LEAD functions
SELECT CASE
        WHEN id = (select max(id) from seat ) AND id%2=1
            then id
        WHEN id%2=1
            then id+1
        ELSE id-1
        END as id,
    student
FROM seat
ORDER BY id