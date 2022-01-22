'''
    12. Write a program that makes use of a function to accept a list of n integers and displays a histogram.
    Author: Anshul Verma
'''

import matplotlib.pyplot as plt

def inputList():
    '''
    To take a input of list of integers from user
    Returns the list
    '''
    ls = []
    length = int(input('Enter the length of list: '))
    for i in range(0, length, 1):
        ls.append(int(input('Enter element {}:'.format(i+1))))
    # Using eval
    # ls = eval(input('Enter the integers: '))
    return ls

if __name__ == "__main__":

    list = inputList()
    plt.hist(list, )
    plt.xlabel('Integer')
    plt.ylabel('Frequency')
    plt.title('Histogram')
    plt.savefig('hist.png', dpi=275, bbox_inches='tight') # To save the plot
    plt.show()
