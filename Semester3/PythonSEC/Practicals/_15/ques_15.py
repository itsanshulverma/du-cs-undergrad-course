'''
15. Define a class Student to store his/ her name and marks in three subjects.
Use a class variable to store the maximum average marks of the class. 
Use constructor and destructor to initialize and destroy the objects.
Author: Anshul Verma
'''

class Student:
    # Class Variable
    max_avg = 0

    # Constructor
    def __init__(self, name='', marks=[0, 0, 0]):
        self.name = name
        self.marks = marks

    # Destructor
    def __del__(self):
        del self.name
        del self.marks
        del self

    def __str__(self):
        str = '\nMarks: {}\n'.format(self.name)
        str += '------------------\n'
        str += 'Subject 1: {}\n'.format(self.marks[0])
        str += 'Subject 2: {}\n'.format(self.marks[1])
        str += 'Subject 3: {}\n'.format(self.marks[2])
        str += 'Average: {:.2f}'.format(self.calcAvg())
        return str

    def calcAvg(self):
        total = 0.0
        for i in range(0, 3, 1):
            total += self.marks[i]
        return total/3

if __name__ == "__main__":

    students = []
    num = int(input('\nEnter the no. of students: '))
    for i in range(1, num+1, 1):
        name = input('\nEnter the name of Student {}: '.format(i))
        marks = []
        for j in range(1, 4, 1):
            marks.append(float(input('Marks in Subject {}: '.format(j))))
        
        student = Student(name, marks)
        if Student.max_avg < student.calcAvg():
            Student.max_avg = student.calcAvg()
        students.append(student)
    
    for i in range(0, len(students), 1):
        print(students[i])
    
    print('\nMaximum average marks of class: {:.2f}\n'.format(Student.max_avg))
    


