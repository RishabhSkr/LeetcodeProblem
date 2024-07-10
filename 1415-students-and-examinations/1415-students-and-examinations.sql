# Write your MySQL query statement below
SELECT a.student_id ,a.student_name,b.subject_name, COUNT(c.subject_name) as attended_exams
FROM Students a 
CROSS JOIN 
    Subjects b
LEFT JOIN 
    Examinations c
            ON a.student_id = c.student_id AND b.subject_name=c.subject_name
GROUP BY c.student_id,a.student_name,b.subject_name
ORDER BY a.student_id,b.subject_name

-- counting  kaunse table se karni and kaunse table se order by group By krna yeh imp h.