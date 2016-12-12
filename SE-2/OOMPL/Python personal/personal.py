class Personal:
    def __init__(self):
        self.name=""
        self.DOB=""
        self.address=""
        self.id=""
    def getPersonalData(self):
        self.name=raw_input("Enter employee's Name:")
        self.DOB=raw_input("Enter employee's Date of Birth:")
        self.address=raw_input("Enter employee's Address:")
        self.id=raw_input("Enter employee's ID:")
    def displayPersonalData(self):
        print("Employee Name : " + self.name)
        print("Employee's DOB: " + self.DOB)
        print("Employee's address:" + self.address)
        print("Employee's ID" + self.id)
  
class Professional:
    def __init__(self):
        self.field=""
        self.company=""
        self.experience=0
        self.designation=""
    def getProfessionalData(self):
        self.field=raw_input("Enter field:")
        self.company=raw_input("Enter Company:")
        self.experience=raw_input("Enter Experience:")
        self.designation=raw_input("Enter Designations:")
    def displayProfessionalData(self):
        print("Field : "+self.field)
        print("Company : "+self.company)
        print("Experience : "+self.experience)
        print("Designation : "+self.designation)
  
class Academic(Personal,Professional):
    def __init__(self):
        self.university=""
        self.grade=""
        self.qualification=""
    def getAcademicData(self):
        self.qualification=raw_input("Enter Qualification:")
        self.grade=raw_input("Enter Grade:")
        self.university=raw_input("Enter University:")
    def displayAcademicData(self):
        print("Qualification : "+self.qualification)
        print("Grade : "+self.grade)
        print("University : "+self.university)

array =list()
while(True):
    print("1. Add Record")
    print("2. List Record")
    print("3. Search for a Record")
    print("4. Delete a Record")
    print("5. Exit")
    ch=int(raw_input("Enter your Choice : "))
    
    if(ch==1):
        print("------------------------------------------------")
        p=Academic()
        p.getPersonalData()
        p.getProfessionalData()
        p.getAcademicData()
        array.append(p)
    
    elif(ch==2):
        print("------------------------------------------------")
        cnt=1
        for i in array: 	
            print("****Record Number "+str(cnt)+"****")
            i.displayPersonalData()
            i.displayProfessionalData()
            i.displayAcademicData()
            cnt+=1
    elif(ch==3):
        print("------------------------------------------------")
        flag=True
        eid=raw_input("Enter employee id:")    
        for i in array:
            if i.id==eid:
                print("Record Found")
                i.displayPersonalData()
                i.displayProfessionalData()
                i.displayAcademicData()
                flag=False
                break
        if flag:
            print("Record Not Found")
    elif(ch==4):
        print("------------------------------------------------")
        flag=False
        eid=raw_input("Enter Employee id:")
        for i in array:
            if i.id==eid:
                print("Record Found and Deleted")
                array.remove(i)
                flag=True
                break
        if not flag:
            print("Record not Found")
    else:
        break        
                
    




