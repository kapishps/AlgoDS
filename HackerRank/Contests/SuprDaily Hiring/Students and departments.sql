/*
Enter your query here.
*/
-- select *
-- from STUDENT as t1
-- right join DEPARTMENT as t2
-- on t1.DEPT_ID = t2.ID
-- where t1.ID is null;


select * from ((select t2.NAME as nm, count(*) as freq
from STUDENT as t1
join DEPARTMENT as t2
on t1.DEPT_ID = t2.ID
group by t2.ID)
UNION
(select t2.NAME as nm, 0 as freq
from STUDENT as t1 right join
DEPARTMENT as t2 on t1.DEPT_ID=
t2.ID where t1.ID is NULL)) as x
order by freq DESC, nm ASC;
