# Write your MySQL query statement below
delete p from person p, person q where p.id>q.id and q.email=p.email