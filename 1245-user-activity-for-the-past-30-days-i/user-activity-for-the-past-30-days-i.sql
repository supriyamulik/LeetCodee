select activity_date as day, COUNT(DISTINCT user_id) as active_users from Activity where activity_date 
BETWEEN '2019-06-28' AND '2019-07-27'
group by activity_date
order by activity_date;