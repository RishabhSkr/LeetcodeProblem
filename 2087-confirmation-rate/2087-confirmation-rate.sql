# Write your MySQL query statement below
SELECT user_id, 
        ROUND(AVG(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END),2) as confirmation_rate
FROM confirmations 
RIGHT JOIN signups USING (user_id)
GROUP BY user_id