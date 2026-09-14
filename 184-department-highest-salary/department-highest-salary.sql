select     
    Department, 
    Employee, 
    Salary from (
select 
     d.name as Department, 
     e.name as Employee, 
     e.salary as Salary,
     rank() over(partition by e.departmentId order by e.salary desc) as max_sal
     FROM Employee e 
    JOIN Department d 
        ON e.departmentId = d.id
) sub
WHERE max_sal = 1;