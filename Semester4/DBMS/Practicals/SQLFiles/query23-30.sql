# query 23
SELECT DISTINCT Job_type
AS 'Unique Jobs in dep 30' 
FROM EMPLOYEE WHERE Dno=30;

# query 24
SELECT Ename, Dname
FROM EMPLOYEE, DEPARTMENT
WHERE EMPLOYEE.Dno=DEPARTMENT.Dno
AND Ename LIKE '%A%';

# query 25
UPDATE DEPARTMENT
SET Location='Dallas'
WHERE Dno=50 or Dno=70;
SELECT Ename, Job_type, E.Dno, Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE E.Dno=D.Dno AND
D.Location='Dallas';

# query 26
SELECT E1.Ename AS 'Name', E1.Eno AS 'Employee No.',
E2.Ename AS "Supervisor's Name",
E1.SupervisonENO AS "Supervisor's Employee No."
FROM EMPLOYEE AS E1
LEFT JOIN EMPLOYEE AS E2
ON E1.SupervisonENO=E2.Eno;

# query 27
SELECT Ename, Dno, Salary
FROM EMPLOYEE 
WHERE (Dno, Salary) IN
(SELECT Dno, Salary
FROM EMPLOYEE
WHERE Commission>0);

SELECT E1.Ename, E1.Dno, E1.Salary
FROM EMPLOYEE AS E1
INNER JOIN EMPLOYEE AS E2
ON E1.Dno=E2.Dno AND E1.Salary=E2.Salary
AND E2.Commission > 0;

# query 28
SELECT Ename, REPEAT('*', Salary/100)
AS 'Salary in *' FROM EMPLOYEE;

# query 29
SELECT MAX(Salary) AS 'Highest Salary',
MIN(Salary) AS 'Lowest Salary',
SUM(Salary) AS 'Sum of Salaries',
AVG(Salary) AS 'Average of Salaries'
FROM EMPLOYEE;

# query 30
SELECT Job_type, COUNT(*) 
FROM EMPLOYEE 
GROUP BY Job_type;