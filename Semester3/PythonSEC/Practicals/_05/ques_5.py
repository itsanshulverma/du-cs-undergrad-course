# Importing factorial function created previously
from ques_3 import factorial

# Function to find sum of given series
def sum_series(x, n):
    sum = 0
    for i in range(1, n+1, 1):
        term = ((-1)**(i+1))*(x**(2*i-2)/factorial(2*i-2)) #Calculating nth term
        sum += term
    return sum

if __name__ == "__main__":
    n = int(input("Enter n: "))
    x = int(input("Enter x: "))
    sum = sum_series(x, n)
    print("\nSum of {} terms of series for x={}: {}".format(n, x, sum))