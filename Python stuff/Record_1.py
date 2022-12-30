'''Create a file ‘sample.txt’ to store some lines of text. Develop a 
menu driven program that provides the following options:-
i) Calculate the number of words in the file
ii) Find the number of words that start with a vowel.
iii) Replace a word with another word. (The word and it’s 
replacement should be accepted from the user)'''

# Taking text from user 
f=open("Sample.txt","w")
while True:
    print("Do you want to enter a line (Y/N)\n")
    n = input("Enter Choice :")
    if n=='Y':
        a = input("Enter Line : ")
        f.write(a+'\n')
    elif n=='N':
        break
f.close()

print('\n')

# Function to calculate words
def calc():
    f=open("Sample.txt",'r')
    f.seek(0)
    n = f.read()
    x = n.split()
    c = 0
    for i in x:
        c+=1
    print("There are " + str(c) +" words in the document")
    f.close()

# Function to ca;culate words starting with a vowel
def vow():
    f=open("Sample.txt",'r')
    f.seek(0)
    n = f.read()
    x = n.split()
    c = 0
    for i in x:
        if i[0] in ('A','E','I','O','U','a','e','i','o','u'):
            c+=1
    print("There are " + str(c) + " words starting with a vowel." )

# Function to replace the word with user input word
def repl():
    f=open("Sample.txt",'r+')
    f.seek(0)
    n = f.read()
    x = n.split()
    c = 0
    for i in x:
        c+=1
    a = input("Enter word to replace :")
    b = input("Enter word to replace with :")
    for i in range(c):
        if x[i]==a:
            x[i]=b
            break
    else:
        print("Word does not exist in file")
    j = n.join()
    f.seek(0)
    f.write(j)
    f.close()

# Menu Driven Program
while True:
    print('\n')
    print("1. Calculate the number of words in the file")
    print("2. Find the number of words that start with a vowel")
    print("3. Replace a word with another word")
    i = int(input("Enter choice :"))
    if i==1:
        calc()
    elif i==2:
        vow()
    elif i==3:
        repl()
    else:
        break