def len_str():
    str = input("Enter the string: ")
    print("Length of string: ", len(str))

def maxof_three():
    str1 = input("Enter string 1: ")
    str2= input("Enter string 2: ")
    str3 = input("Enter string 3: ")
    maxstr = ""
    if str1 > str2 and str1 > str3:
        maxstr = str1
    elif str2 > str1 and str2 > str3:
        maxstr = str2
    else:
        maxstr = str3
    print("Maximum of above three: ", maxstr)

def replace_vowels():
    str = input("Enter the string: ")
    new_str = ""
    vowels = ['a','e','i','o','u']
    for i in range(0, len(str), 1):
        if str[i].lower() in vowels:
            new_str += "#"
        else:
            new_str += str[i]
    print("Replaced string: ", new_str)

def numofwords():
    str = input("Enter the string: ")
    str = str.strip() + " "
    count = 0
    for i in range(0, len(str), 1):
        if str[i] == " ":
            count += 1
    print("No of words: ", count)

def palindrome():
    str = input("Enter the string: ")
    new_str = ""
    for i in range(0, len(str), 1):
        new_str = str[i] + new_str
    if str == new_str:
        print(f"{str} is a palindrome.")
    else:
        print(f"{str} is not a palindrome")

def main():
    print("\nMenu")
    print("-"*20)
    print("1. Length of string")
    print("2. Maximum of three strings")
    print("3. Replace vowels with '#'")
    print("4. No. of words")
    print("5. Check Palindrome")
    print("6. Exit")
    print("-"*20)
    option = input("Your choice: ")

    switcher = {
        '1' : len_str,
        '2' : maxof_three,
        '3' : replace_vowels,
        '4' : numofwords,
        '5' : palindrome,
        '6' : quit
    }
    func = switcher.get(option, lambda: print("Invalid Choice!"))
    func()

if __name__ == "__main__":

    ch = 'y'
    while ch.lower() == 'y':
        main()
        ch = input("\nWant to continue? [y/n]: ")
        