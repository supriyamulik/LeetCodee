select query_name, ROUND(AVG(rating/position), 2) as quality, 
ROUND(AVG(IF(rating < 3, 1, 0)*100), 2) as poor_query_percentage
from Queries GROUP BY query_name;