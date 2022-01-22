def primes(T1):
    T2 = []
    primeCubes = {}
    for num in T1:
        if num > 1:
            for i in range(2, num):
                if num % i == 0:
                    break
            else:
                T2.append(num)
                primeCubes[num] = num**3
    return primeCubes

t1 = (1,2,5,7,9,3,4,6,8,10)
print(t1)
primeCubes = primes(t1)
print(primeCubes)