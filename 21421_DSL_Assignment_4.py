class Student:

    def __init__(self,no_of_students):
        self.n=no_of_students
        self.arr=[]

    def make_arr(self):
        for i in range(self.n):
            self.arr.append(int(input(f"Enter roll number of student {i+1} : ")))

    def linear_search(self,roll_no):
        flag=0
        for i in range(self.n):
            if (self.arr[i]==roll_no):
                print(f"Roll No {roll_no} attended the training program and his position was {i+1}")
                flag=1
                break
        if(flag!=1):
            print(f"Roll No {roll_no} not attended the training program")

    def sentinel_search(self,roll_no):
        last=self.arr[self.n-1]
        self.arr[self.n-1]=roll_no
        i=0
        while(self.arr[i]!=roll_no):
            i+=1
        self.arr[self.n-1]=last
        if (i<(self.n-1) or roll_no==self.arr[self.n-1]):
            print(f"Roll No {roll_no} attended the training program and his position was {i+1}")
        else:
            print(f"Roll No {roll_no} not attended the training program")

    def binary_search(self,roll_no):
        initial=self.arr.copy()
        self.arr.sort()
        low=0
        high=len(self.arr)-1
        check=0
        while(low<=high):
            mid=int(((low+high)/2))
            if self.arr[mid]==roll_no:
                check=1
                break
            elif self.arr[mid]>roll_no:
                high=mid-1
            else:
                low=mid+1
        if check==1:
            print(f"Roll No {roll_no} attended the training program and his position was {initial.index(roll_no)+1}")
        else:
            print(f"Roll No {roll_no} not attended the training program")

    def fibonacci_search(self,roll_no):
        initial = self.arr.copy()
        self.arr.sort()
        size = len(self.arr)
        start = -1
        check=0
        f0 = 0
        f1 = 1
        f2 = 1
        while(f2 < size):
            f0 = f1
            f1 = f2
            f2 = f1 + f0
        while(f2 > 1):
            index = min(start + f0, size - 1)
            if self.arr[index] < roll_no:
                f2 = f1
                f1 = f0
                f0 = f2 - f1
                start = index
            elif self.arr[index] > roll_no:
                f2 = f0
                f1 = f1 - f0
                f0 = f2 - f1
            else:
                print(f"Roll No {roll_no} attended the training program and his position was {initial.index(roll_no)+1}")
                check=1
                break
        if (f1) and (self.arr[size - 1] == roll_no):
            print(f"Roll No {roll_no} attended the training program and his position was {initial.index(roll_no)+1}")
        if check!=1:
            print(f"Roll No {roll_no} not attended the training program")

while(True):
    print("\nSearching : \n1-Linear Search \n2-Sentinel Search \n3-Binary Search \n4-Fibonacci Search \n5-Quit")
    choice=input("\nEnter your choice : ")
    if choice=='5':
        break
    t=int(input("\nEnter total number of students : "))
    print()
    s1=Student(t)
    s1.make_arr()
    no=int(input("\nEnter roll number of student to be search : "))

    if choice=='1':
        s1.linear_search(no)
    elif choice=='2':
        s1.sentinel_search(no)
    elif choice=='3':
        s1.binary_search(no)
    elif choice=='4':
        s1.fibonacci_search(no)