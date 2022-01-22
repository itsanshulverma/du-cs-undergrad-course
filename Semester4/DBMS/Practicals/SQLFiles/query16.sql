SELECT CURDATE() AS 'Current Date',
DAYNAME(CURDATE()) AS 'Day Name';

SELECT CONCAT(CURDATE(),', ',
DAYNAME(CURDATE())) 
AS 'Current Date, Day Name';