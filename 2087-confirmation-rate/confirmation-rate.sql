select s.user_id, ifnull(round(SUM(action = 'confirmed')/COUNT(*), 2), 0.00) as confirmation_rate
from Signups s
LEFT JOIN Confirmations c
on s.user_id = c.user_id
GROUP BY s.user_id;