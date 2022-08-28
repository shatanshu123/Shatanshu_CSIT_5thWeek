# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete p2 from person p2,person p1 where p1.email=p2.email and p1.id<p2.id;