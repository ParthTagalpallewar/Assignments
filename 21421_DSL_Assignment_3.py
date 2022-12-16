class Matrix:

    #Intialization of rows and column
    def __init__(self,n,m):
        self.m=m
        self.n=n

    #Getting values of matrix
    def make_matrix(self):
        self.matrix=[]
        for i in range(self.m):
            rows=[]
            for j in range(self.n):
                rows.append(int(input("Enter value [{}][{}] : ".format(i,j))))
            self.matrix.append(rows)
        print("\nMatrix : ")
        for m in self.matrix:
            for n in m:
                print(n,end=" ")
            print()
        print()

    #Displaying values of matrix
    def printmatrix(self,M):
        for m in M:
            for n in m:
                print(n,end=" ")
            print()
        print()

    #Making null matrix for multiplication
    def base_matrix1(self,p,q):
        self.result1=[]
        for i in range(p.m):
            rows=[]
            for j in range(q.n):
                rows.append(0)
            self.result1.append(rows)

    #Making null matrix for transpose
    def base_matrix2(self,r):
        self.result2=[]
        for i in range(r.n):
            rows=[]
            for j in range(r.m):
                rows.append(0)
            self.result2.append(rows)

    #Addition of two matrices
    def add(self,a,b):
        A=[]
        for i in range(len(a.matrix)):
            rows=[]
            for j in range(len(a.matrix[i])):
                rows.append(a.matrix[i][j]+b.matrix[i][j])
            A.append(rows)
        print("\nAddition : ")
        self.printmatrix(A)

    #Subtraction of two matrices
    def sub(self,a,b):
        S=[]
        for i in range(len(a.matrix)):
            rows=[]
            for j in range(len(a.matrix[i])):
                rows.append(a.matrix[i][j]-b.matrix[i][j])
            S.append(rows)
        print("\nSubtraction : ")
        self.printmatrix(S)

    #Multiplication of two matrices
    def multiply(self,a,b):
        a.base_matrix1(a,b)
        for i in range(len(a.matrix)):
            for j in range(len(b.matrix[0])):
                for k in range(len(b.matrix)):
                    a.result1[i][j] += a.matrix[i][k] * b.matrix[k][j]
        print("\nMutiplucation : ")
        self.printmatrix(a.result1)
 
    #Transpose of two matrices
    def transpose(self,a):
        a.base_matrix2(a)
        for i in range(len(a.matrix[0])):
            for j in range(len(a.matrix)):
                a.result2[i][j]=a.matrix[j][i]
        self.printmatrix(a.result2)

print("\nFirst Matrix")
a1=int(input("\nEnter no. of rows : "))
b1=int(input("Enter no. of columns : "))
print()
m1=Matrix(b1,a1)
m1.make_matrix()

print("\nSecond Matrix")
a2=int(input("\nEnter no. of rows : "))
b2=int(input("Enter no. of columns : "))
print()
m2=Matrix(b2,a2)
m2.make_matrix()

while(True):
    print("\n1-Addition \n2-Subtraction \n3-Multiplication \n4-Transpose \n5-Quit")
    choice=int(input("\nEnter your choice : "))
    m3=Matrix(0,0)
    if (choice==1):
        if (a1==a2) and (b1==b2):
            m3.add(m1,m2)
        else:
            print("\nAddition not possible")
    elif (choice==2):
         if (a1==a2) and (b1==b2):
            m3.sub(m1,m2)
         else:
             print("\nSubtraction not possible")
    elif (choice==3):
        if (b1==a2):
             m3.multiply(m1,m2)
        else:
             print("\nMultiplication not possible")
    elif (choice==4):
         print("\nTranspose of 1st Matrix : ")
         m3.transpose(m1)
         print("Transpose of 2nd Matrix : ")
         m3.transpose(m2)
    elif (choice==5):
         break
    else:
         print("\nEnter valid input !!! ")