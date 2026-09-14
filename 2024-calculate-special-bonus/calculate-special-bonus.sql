select e.employee_id,
       CASE when e.employee_id%2=1 and e.name not like 'M%' then e.salary
       ELSE 0
       END AS bonus
    from Employees e order by employee_id;