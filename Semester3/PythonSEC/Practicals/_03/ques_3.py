# Factorial function to find factorial of a number
def factorial(n):
    if n <= 1:
        return 1
    return n*factorial(n-1)

# Fibonacci function to find nth term of series
def fib(n): #Recursive
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return fib(n-1) + fib(n-2)

# def fib(n): #Iterative
#     pnum = 0
#     ppnum = 0
#     cnum = 1
#     for i in range(n):
#         ppnum = pnum
#         pnum = cnum
#         cnum = pnum + ppnum
#     return cnum

# Main 
if __name__ == "__main__":
    num =  int(input("Enter a number: "))
    print("{}th term of fibonacci series: ".format(num), fib(num))
    print("Factorial of {}: ".format(num), factorial(num))