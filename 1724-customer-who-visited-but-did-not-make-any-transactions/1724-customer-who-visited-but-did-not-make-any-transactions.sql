# Write your MySQL query statement below
SELECT a.customer_id,COUNT(a.customer_id) as count_no_trans
FROM Visits as a
WHERE a.visit_id NOT IN(
    SELECT visit_id
    FROM Transactions
)
GROUP BY a.customer_id
