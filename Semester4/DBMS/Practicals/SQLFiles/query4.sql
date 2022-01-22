# Query 4

SELECT CONCAT(Eno,', ', Ename,', ',
Job_type,', ',
IFNULL(SupervisonENO,''),', ',
Hire_date,', ',
IFNULL(Dno,''),', ',
IFNULL(Commission,''),', ',
Salary) AS THE_OUTPUT
FROM EMPLOYEE;

SELECT CONCAT_WS(', ',Eno,Ename,
Job_type,SupervisonENO,Hire_date,
Dno,Commission,Salary) 
AS THE_OUTPUT 
FROM EMPLOYEE;