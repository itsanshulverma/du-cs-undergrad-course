'''
9. Use dictionary to store marks of the students in 4 subjects. 
Write a function to find the name of the student securing highest percentage. 
(Hint: Names of students are unique).
Author: Anshul Verma (19/78065)
'''

def findTopStudent(marks):
    name = ''
    percentage = 0.0
    for student in marks:
        marks_list = marks[student]
        total = 0.0
        for i in range(0, len(marks_list), 1):
            total += marks_list[i]
        if percentage < total/4:
            percentage = total/4
            name = student
    return name

if __name__ ==  "__main__":
    marks = {}
    num = int(input('Enter the no. of students: '))
    for i in range(1, num+1, 1):
        name = input('\nEnter the name of Student {}: '.format(i))
        temp = []
        for j in range(1, 5, 1):
            mark = float(input('Marks in Subject {}(out of 100): '.format(j)))
            temp.append(mark)
        marks[name] = temp

    topper = findTopStudent(marks)
    print('\n{} secured the highest percentage.'.format(topper))