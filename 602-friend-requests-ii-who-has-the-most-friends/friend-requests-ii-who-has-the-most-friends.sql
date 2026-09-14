select id, COUNT(*) as num from(
select requester_id as id, accepter_id as friend from RequestAccepted
UNION 
select accepter_id as id, requester_id as frined from RequestAccepted
) a group by id order by num desc limit 1;