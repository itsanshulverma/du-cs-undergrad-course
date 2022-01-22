
SELECT Ename, Hire_date
FROM EMPLOYEE
WHERE YEAR(Hire_date) = 1981;

SELECT Ename, Hire_date
FROM EMPLOYEE
WHERE Hire_date LIKE '1981%';
