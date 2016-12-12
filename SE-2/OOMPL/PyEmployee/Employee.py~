class Employee:
    def __init__(self):
        self.name = ""
        self.address = ""
        self.DOB = ""
        self.id = ""
    
    def get_employee_data(self):
        self.name = raw_input("Enter name: ")
        self.address = raw_input("Enter address: ")
        self.DOB = raw_input("Enter date of birth: ")
        self.id = raw_input("Enter employee id: ")
    
    def print_emp_data(self):
        print("Name : " + self.name)
        print("Address: " + self.address)
        print("DOB: " + self.DOB)
        print("Employee ID: " + self.id)
        
class Professional:
    def __init__(self):
        self.desig = ""
        self.experience = ""
        self.area_of_exp = ""
    
    def get_prof_data(self):
        self.desig = raw_input("Enter designation: ")
        self.experience = raw_input("Enter experience: ")
        self.area_of_exp = raw_input("Enter area of experience: ")
        
    def print_prof_data(self):
        print("Designation: " + self.desig)
        print("Experience: " + self.experience)
        print("Area of Experience: " + self.area_of_exp)

class Academic(Employee, Professional):
    def __init__(self):
        self.qualif = ""
        self.grade = ""
        self.univ = ""
    
    def get_aca_data(self):
        self.qualif = raw_input("Enter qualification: ")
        self.grade = raw_input("Enter grade: ")
        self.univ = raw_input("Enter university: ")
    
    def print_aca_data(self):
        print("Qualification: " + self.qualif)
        print("Grade: " + self.grade)
        print("University: " + self.univ)    
        
l = list()

print("Employee Database")

while True:
    print("1. Enter a record")
    print("2. List records")
    print("3. Search for a record")
    print("4. Delete a record")
    print("5. Exit")
    
    ch = int(raw_input("Enter your choice: "))
    
    if ch == 1:
        p = Academic()
        p.get_employee_data()
        p.get_prof_data()
        p.get_aca_data()
        l.append(p)
    elif ch == 2:
        i = 1
        for a in l:
            print("Record " + str(i))
            a.print_emp_data()
            a.print_prof_data()
            a.print_aca_data()
            i = i + 1
            print("--------------------")
        
    elif ch == 3:
        eid = raw_input("Enter employee id to search: ")
        found = False
        for a in l:
            if a.id == eid:
                found = True
                print("Record Found: ")
                a.print_emp_data()
                a.print_prof_data()
                a.print_aca_data()
                break
        if not found:
            print("Record not found.")
        
    elif ch == 4:
        eid = raw_input("Enter employee id to search: ")
        found = False
        for a in l:
            if a.id == eid:
                found = True
                l.remove(a)
                print("Record deleted")
                break
        if not found:
            print("Record not found.")
    elif ch == 5:
        break
    
