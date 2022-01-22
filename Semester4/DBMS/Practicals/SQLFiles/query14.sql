
SELECT Ename FROM EMPLOYEE
WHERE (Ename LIKE '%r%r%' OR Ename LIKE '%a%a%')
AND (Dno=30 OR SupervisonENO='778');