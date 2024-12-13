SELECT salary as SecondHighestSalary 
FROM employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
