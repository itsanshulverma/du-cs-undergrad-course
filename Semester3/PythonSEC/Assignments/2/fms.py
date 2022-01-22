# Write a programme to create FMS of student to handle write, read and delete operations

class StudentFMS:
    
    def __init__(self, file):
        self.file = file

    def read(self):
        f = open(self.file, 'r')
        lines = f.readlines()
        for line in lines:
            print(line.strip())
        f.close()
        return lines

    def write(self, name):
        fr = open(self.file,'r')
        lines = fr.readlines()
        fw = open(self.file,'a')
        if len(lines) > 0:
            fw.write('\n')
        fw.write(name)
        fw.close()

    def delete(self, name):
        fr = open(self.file,'r')
        lines = fr.readlines()
        fr.close()
        fw = open(self.file,'w')
        for line in lines:
            if line.strip().lower() != name.lower():
                fw.write(line)
        fw.close()

students = StudentFMS('students.txt')
print('\nWrite: Michael')
students.write('Michael')
print('\nWrite: John Cena')
students.write('John Cena')
print('\nWrite: Anshul Verma')
students.write('Anshul Verma')
print('\nRead:')
students.read()
print('\nDelete: John Cena')
students.delete('John Cena')
print('\nRead:')
students.read()

