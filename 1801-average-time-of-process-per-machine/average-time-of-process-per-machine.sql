with a as (
    select * from activity where activity_type = 'start'
),
b as (
    select * from activity where activity_type = 'end'
)
select a.machine_id, round(avg(b.timestamp - a.timestamp), 3) as 'processing_time' from a
join b on a.machine_id = b.machine_id and a.process_id = b.process_id group by a.machine_id;