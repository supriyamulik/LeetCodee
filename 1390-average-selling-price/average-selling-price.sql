select p.product_id, IFNULL(ROUND(SUM(p.price*u.units) / SUM(u.units), 2), 0) as average_price
from Prices p LEFT JOIN UnitsSold u
ON P.product_id = U.product_id 
AND u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
GROUP BY product_id;