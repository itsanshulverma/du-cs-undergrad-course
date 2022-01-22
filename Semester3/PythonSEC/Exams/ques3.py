class Salesman:

    def __init__ (self, name, region, basicPay):
        self.name = name
        self.region = region
        self.basicPay = eval(basicPay)
        if region == 'Delhi':
            self.HRA  = 4000
        elif region == 'Mumbai':
            self.HRA = 8000
        self.salary = self.grossSalary()

    def grossSalary(self):
        return self.basicPay + self.HRA

    def display(self):
        info = f'''
            Salesman Info
            -------------------
            Name: {self.name}
            Region: {self.region}
            Basic Pay: Rupees {self.basicPay}
            HRA: Rupees {self.HRA}
            Salary: Rupees {self.salary}
            '''
        print(info)

salesman1 = Salesman('Raman', 'Delhi', '20000')
salesman2 = Salesman('Aman', 'Mumbai', '20000')
salesman1.display()
salesman2.display()