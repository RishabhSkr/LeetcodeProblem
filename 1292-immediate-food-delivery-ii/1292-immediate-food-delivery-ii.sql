WITH FirstOrders AS (
    SELECT
        customer_id,
        MIN(order_date) AS first_order_date
    FROM
        Delivery
    GROUP BY
        customer_id
),

ImmediateOrders AS (
    SELECT
        fo.customer_id,
        CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END AS is_immediate
    FROM
        FirstOrders fo
        JOIN Delivery d ON fo.customer_id = d.customer_id AND fo.first_order_date = d.order_date
)

SELECT
    ROUND(AVG(is_immediate) * 100.0, 2) AS immediate_percentage
FROM
    ImmediateOrders;
