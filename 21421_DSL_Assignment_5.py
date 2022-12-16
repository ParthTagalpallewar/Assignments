class Student:
    def __init__(self,no_of_student):
        self.n=no_of_student
        self.arr=[]
        print("\nEnter percentages : ")
        for i in range(self.n):
            self.arr.append(float(input(f"Student {i+1} : ")))
        print("Percentage List : ",self.arr)

    def insertion_sort(self):
        for i in range(len(self.arr)):
            temp=self.arr[i]
            j=i-1
            while(j>=0 and self.arr[j]>temp):
                self.arr[j+1]=self.arr[j]
                j-=1
            self.arr[j+1]=temp
        print("Percentage List : ",self.arr)

    def shell_sort(self):
        gap=self.n//2
        while(gap>=1):
            i=gap
            while(i<self.n):
                j=i-gap
                while(j>=0):
                    if(self.arr[j+gap]>self.arr[j]):
                        break
                    else:
                        self.arr[j+gap],self.arr[j] = self.arr[j],self.arr[j+gap]
                    j=j-gap
                i+=1
            gap //= 2
        print("Percentage List : ",self.arr)

num=int(input("Enter total number of student : "))
S=Student(num)

while(True):
    print("\n1-Insertion Sort\n2-Shell Sort\nQ-Quit")
    choice=input("\nEnter your choice : ")
    if choice=='1':
        S.insertion_sort()
        print("Top five : ",[S.arr[-i] for i in range(1,6)])
    elif choice=='2':
        S.shell_sort()
        print("Top five : ",[S.arr[-i] for i in range(1,6)])
    elif choice=='Q':
        break
    else:
        print("Invalid input !")


