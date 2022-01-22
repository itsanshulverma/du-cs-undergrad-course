# Tuple t1
t1 = (1,2,5,7,9,2,4,6,8,10)
print("Given tuple: ", t1)

# Another tuple with even values of t1
t_even = ()
for i in range(0, len(t1), 1):
    if t1[i] % 2 == 0:
        t_even += (t1[i],)
print("New tuple with even values: ", t_even)

# Concatenate t2 with t1
t2 = (11, 13, 15)
t3 = t1 + t2
print("Concatented tuple: ", t3)

# Maximum and minimum values from concatenated tuple
maximum = t3[0]
minimum = t3[0]
for i in range(0, len(t3), 1):
    if t3[i] > maximum:
        maximum = t3[i]
    if t3[i] < minimum:
        minimum = t3[i]
print("Maximum: ", maximum)
print("Minimum: ", minimum)