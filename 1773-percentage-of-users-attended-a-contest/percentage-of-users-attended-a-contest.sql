select r.contest_id, ROUND(COUNT(DISTINCT r.user_id)*100 / (select COUNT(*) FROM users), 2) as percentage
FROM Users u RIGHT JOIN Register r ON u.user_id = r.user_id
GROUP BY R.contest_id ORDER BY percentage DESC, contest_id ASC ;