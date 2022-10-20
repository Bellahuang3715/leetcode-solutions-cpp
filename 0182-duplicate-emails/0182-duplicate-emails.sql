# Write your MySQL query statement below

SELECT DISTINCT T1.email as Email
FROM (Person AS T1) CROSS JOIN (Person AS T2)
WHERE T1.id != T2.id AND T1.email = T2.email;