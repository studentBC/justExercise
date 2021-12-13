# Write your MySQL query statement below
select customer_id, name from 
    Customers join Orders using (customer_id)
    join Product using (product_id)
group by customer_id
having SUM(IF(LEFT(order_date, 7) = '2020-06', quantity, 0) * price) > 99 and 
SUM(IF(LEFT(order_date, 7) = '2020-07', quantity, 0) * price) > 99;

#559 ms solution
# Write your MySQL query statement below
SELECT
    customer_id,
    name
FROM
    orders o
    JOIN product p USING (product_id)
    JOIN customers c USING (customer_id)
WHERE
    order_date BETWEEN "2020-06-01" AND "2020-07-31"
GROUP BY
    customer_id
HAVING
    sum(case when month(order_date) = '06' then price*quantity else 0 end)>=100 AND
    sum(case when month(order_date) = '07' then price*quantity else 0 end)>=100;
