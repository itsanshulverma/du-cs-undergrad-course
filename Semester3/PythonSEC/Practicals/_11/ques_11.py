'''
11 . Write a menu-driven program to accept a list of student names and perform the following
a. search an element using linear search/ binary search.
b. Sort the elements using bubble sort/ insertion sort/ selection sort.
Author: Anshul Verma (19/78065)
'''

def bubbleSort(list):
    for i in range(0, len(list)-1, 1):
        for j in range(0, len(list) - i - 1, 1):
            if list[j] > list[j+1]:
                temp = list[j]
                list[j] = list[j+1]
                list[j+1] = temp
    return list

def insertionSort(list):
    for i in range(0, len(list), 1):
        temp = list[i]
        j = i - 1
        while j >= 0 and list[j] > temp:
            list[j+1] = list[j]
            j -= 1
        list[j+1] = temp
    return list

def selectionSort(list):
    for i in range(0, len(list)-1, 1):
        minIndex = i
        for j in range(i+1, len(list), 1):
            if list[minIndex] > list[j]:
                minIndex = j
        temp = list[minIndex]
        list[minIndex] = list[i]
        list[i] = temp
    return list

def linearSearch(list, element):
    for i in range(0, len(list), 1):
        if list[i].lower() == element.lower():
            return i
    return -1

def binarySearch(list, element):
    list = selectionSort(list)
    low = 0
    high = len(names) - 1
    while low <= high:
        mid = int(low + (high - low) / 2)
        if (list[mid] == element):
            return mid
        if (list[mid] > element):
            high = mid - 1
        else:
            low = mid + 1
    return -1

if __name__ == "__main__":
    num = int(input('\nEnter the number of students: '))
    print('Enter the names of students:')
    names = []
    for i in range(0, num, 1):
        names.append(input('{}: '.format(i+1)))
    
    choice = 'y'
    while choice.lower() == 'y':
        print('\n-------- Menu --------')
        print('1. Search a name')
        print('2. Sort the list of names')
        choice = input('Your Choice: ')
        if choice == '1':
            name = input('\nEnter a name to search: ')
            choice = input('Choose a searching algorithm:\n1. Linear, 2. Binary: ')
            index = -1
            if choice == '1':
                index = linearSearch(names, name)
            elif choice == '2':
                index = binarySearch(names, name)
            else:
                print('Invalid Choice!') 
            if index == -1:
                print('Name is not in the list.')
            else:
                print('Name found in the list.')
        elif choice == '2':
            choice = input('Choose a sorting algorithm:\n1. Bubble, 2. Insertion, 3. Selection: ')
            sorted_names = []
            if choice == '1':
                sorted_names = bubbleSort(names)
            elif choice == '2':
                sorted_names = insertionSort(names)
            elif choice == '3':
                sorted_names = selectionSort(names)
            else:
                print('Invalid Choice!') 
            print('Sorted list: ', end='')
            for i in range(0, len(sorted_names), 1):
                print('\'{}\''.format(sorted_names[i]), end=' ')
            print('')
        else:
            print('Invalid Choice!')
        
        choice = input('\nWould you like to continue? (y/n): ')