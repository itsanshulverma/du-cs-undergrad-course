# query 31
SELECT COUNT(DISTINCT SupervisonENO) 
AS 'Total No. of Supervisors' FROM EMPLOYEE;

# query 32
SELECT D.Dname, D.Location,
COUNT(*) AS 'No of Employees',
AVG(E.Salary) AS 'Average of Salaries'
FROM DEPARTMENT AS D, EMPLOYEE AS E
WHERE D.Dno = E.Dno
GROUP BY E.Dno;

# query 33
INSERT INTO EMPLOYEE
VALUES('786','Blake','Clerk','540',1996-08-21,20,159.54,2570.99);

SELECT Ename, Hire_date FROM EMPLOYEE
WHERE Dno = (SELECT Dno FROM EMPLOYEE
WHERE Ename = "Blake");

# query 34
SELECT Eno, EName FROM EMPLOYEE 
WHERE Salary > 
(SELECT AVG(Salary) FROM EMPLOYEE);

# query 35
SELECT Eno, Ename FROM EMPLOYEE
WHERE Dno IN (SELECT Dno FROM EMPLOYEE
WHERE Ename LIKE "%T%");

# query 36
INSERT INTO EMPLOYEE
VALUES('586','King','Manager','500',1996-08-21,20,159.54,2570.99),
('780','Bhavesh Joshi','Clerk','586',1999-08-13,20,200.00,2140.00),
('785','Pitbull','Salesman','586',2000-11-01,20,1590.50,3164.00),
('795','Enrique Iglesias','Salesman','586',1993-04-21,20,1130.54,3350.50),
('770','Gajendra Verma','Accountant','586',1995-02-05,20,69.99,3570.45),
('809','Aisha Takia','Salesman','586',2004-04-21,05,2500.64,1940.00),
('807','Prateek Kuhad','Analyst','586',2006-09-21,07,10.00,2670.59);

SELECT E1.Ename, E1.Salary 
FROM EMPLOYEE AS E1, EMPLOYEE AS E2
WHERE E1.SupervisonENO=E2.Eno AND
E2.Ename = "King";

# query 37
SELECT D.Dno, E.Ename, E.Job_type
FROM DEPARTMENT AS D, EMPLOYEE AS E
WHERE E.Dno = D.Dno
AND D.Dname = "Sales";

# query 38
SELECT E.Ename, D.Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE E.Dno = D.Dno AND
YEAR(FROM_DAYS(
DATEDIFF(CURDATE(), Hire_date))) > 20;

# query 39
SELECT COUNT(*) AS 'No. of departments', 
Location FROM DEPARTMENT
GROUP BY Location;

# query 40
INSERT INTO EMPLOYEE
VALUES('742','Kunal Khemu','Salesman','586',1999-08-13,20,200.00,2140.00),
('743','Chris Brown','Salesman','533',2000-11-01,20,1590.50,3164.00),
('739','Drake','Salesman','540',1993-04-21,20,1130.54,3350.50),
('735','Arijit Singh','Accountant','540',1995-02-05,20,69.99,3570.45),
('757','Ram Sampath','Salesman','586',2004-04-21,05,2500.64,1940.00),
('750','Anweshaa','Analyst','540',2006-09-21,07,10.00,2670.59);

SELECT D.Dname, COUNT(*) 
FROM DEPARTMENT AS D, EMPLOYEE AS E
WHERE D.Dno = E.Dno 
GROUP BY E.Dno HAVING COUNT(*) >= 20;

# query 41
SELECT E1.Ename FROM EMPLOYEE E1
WHERE NOT EXISTS
(SELECT * FROM EMPLOYEE E2 
WHERE E1.Eno = E2.SupervisonENO)
UNION
SELECT Ename FROM EMPLOYEE
WHERE Eno IN
(SELECT SupervisonENO FROM EMPLOYEE
GROUP BY SupervisonENO 
HAVING COUNT(*) > 5);

# query 42
(SELECT Job_type AS "Job_type with Max & Min Employees", 
COUNT(*) AS "# of Employees"
FROM EMPLOYEE GROUP BY Job_type
HAVING COUNT(*) = (SELECT MAX(_count)
FROM (SELECT COUNT(*) AS _count
FROM EMPLOYEE GROUP BY Job_type) AS A))
UNION
(SELECT Job_type, COUNT(*)
FROM EMPLOYEE GROUP BY Job_type
HAVING COUNT(*) = (SELECT MIN(_count)
FROM (SELECT COUNT(*) AS _count
FROM EMPLOYEE GROUP BY Job_type) AS B));

SELECT E1.Job_type AS "Job type with Max Employees",
E2.Job_type AS "Job type with Min Employees"
FROM EMPLOYEE AS E1, EMPLOYEE AS E2
GROUP BY E1.Job_type
HAVING COUNT(*) = (SELECT MAX(_count)
FROM (SELECT COUNT(*) AS _count
FROM EMPLOYEE GROUP BY Job_type) AS A)
OR COUNT(*) = (SELECT MIN(_count)
FROM (SELECT COUNT(*) AS _count
FROM EMPLOYEE GROUP BY Job_type) AS A);