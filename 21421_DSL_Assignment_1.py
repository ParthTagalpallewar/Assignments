# Union
def union(S1, S2):
    S = S1.copy()
    for i in range(len(S2)):
        if S2[i] not in S:
            S.append(S2[i])
    return S

# Intersection
def intersection(S1,S2):
    S = []
    for i in range(len(S2)):
        if S2[i] in S1:
            S.append(S2[i])
    return S

# Difference
def difference(S1,S2):
    S = S1.copy()
    for i in range(len(S2)):
        if S2[i] in S1:
            S.remove(S2[i])
    return S

# Total Students
num = int(input("Enter a total number of students : "))
U = [(i + 1) for i in range(num)]
print("Roll No of all students = ", U)

# Cricket
Cricket = int(input("\nEnter total number of students who play Cricket : "))
C = []
print("Enter roll numbers ")
for i in range(Cricket):
    num = int(input())
    if num not in C:
        C.append(num)
print("Students who play cricket : ", C)

# Badminton
Badminton = int(input("\nEnter total number of students who play Badminton : "))
B = []
print("Enter roll numbers ")
for i in range(Badminton):
    num = int(input())
    if num not in B:
        B.append(num)
print("Students who play badminton : ", B)

# Football
Football = int(input("\nEnter total number of students who play Football : "))
F = []
print("Enter roll numbers ")
for i in range(Football):
    num = int(input())
    if num not in F:
        F.append(num)
print("Students who play Football : ", F)

while(True):
    print("\na-List of students who play both cricket and badminton")
    print("b-List of students who play either cricket or badminton but not both")
    print("c-Number of students play neither cricket nor badminton")
    print("d-Number of students who play cricket and football but not badminton")
    print("q-Quit")
    n=input("Enter your choice : ")

    if n=='a':
        print(intersection(C, B))
    elif n=='b':
        print(difference(union(C, B), intersection(C, B)))
    elif n=='c':
        print(len(difference(U, union(C, B))))
    elif n=='d':
        print(len(difference(intersection(C, F), B)))
    elif n=='q':
        break
    else:
        print("Invalid Input !!!")
