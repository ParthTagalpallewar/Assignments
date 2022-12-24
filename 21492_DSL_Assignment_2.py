class String:

    def length(self, str1):
        length = 0
        for i in str1:
            length = length + 1
        return length

    def splitstr(self, str1):
        A = []
        word = ''
        for i in str1:
            if i == " ":
                A.append(word)
                word = ''
            else:
                word = word + i
        A.append(word)
        return A

    def largest(self,str):
        word = ''
        str_list = []
        for i in range(len(str)):
            if str[i] == " ":
                str_list.append(word)
                word = ''
                continue
            word = word + str[i]
            if i == len(str) - 1:
                str_list.append(word)
        large=0
        for i in str_list:
            if len(i) > large:
                large = len(i)
                word = i
        for j in str_list:
            if len(word) == len(j):
                print(j)

    def frequency(self,str,char):
        count=0
        for i in range(len(str)):
            if char == str[i]:
                count = count + 1 
        print(count)

    def palindrome(self,str):
        reverse_str = ''
        for i in range(len(str)):
            reverse_str = str[i] + reverse_str
        if str == reverse_str:
            print("Yes,It is palindrome !")
        else:
            print("It is not a palindrome !")

    def appearance(self,str,sub_str):
        for i in range(len(str)):
            if str[i] == sub_str[0]:
                if len(sub_str)==1:
                    print(i)
                    break
                index=i
                j = i + 1
                k = 1
                while (sub_str[k] == str[j]):
                    if k == (len(sub_str)-1):
                        print(index)
                        break
                    j += 1
                    k += 1

    def occurrence_of_word(self, str1):
        duplicate = []
        str1 = str1.lower()
        list_a = self.splitstr(str1)
        ln = self.length(list_a)
        for i in range(0, ln):
            word = list_a[i]
            count = 0
            if word not in duplicate:
                duplicate.append(list_a[i])
                for j in list_a:
                    if word == j:
                        count = count + 1
                print(word, "-->", count)

string=input("Enter a string : ")
while(True):
    obj=String()
    print("\na-Word with largest length")
    print("b-Frequency of occurrence of particular character in the string")
    print("c-String is palindrome or not")
    print("d-Index of first appearance of the substring")
    print("e-Count the occurrences of each word in a given string")
    print("q-Quit")
    n=input("\nEnter your choice : ")
    if n=='a':
        obj.largest(string)
    elif n=='b':
        s2=input("Enter a character : ")
        obj.frequency(string,s2)
    elif n=='c':
        obj.palindrome(string)
    elif n=='d':
        s2=input("Enter a substring : ")
        obj.appearance(string,s2)
    elif n=='e':
        obj.occurrence_of_word(string)
    elif n=='q':
        break
    else:
        print("Enter valid input !!")
