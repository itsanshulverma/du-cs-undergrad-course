SELECT Ename, Hire_date,
DAYOFWEEK(Hire_date) 
AS 'Day of Week when Hired'
FROM EMPLOYEE;