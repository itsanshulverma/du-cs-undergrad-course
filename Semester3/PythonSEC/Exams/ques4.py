def readData(infilename, outfilename, ch):
    infile = open(infilename, 'r')
    outfile = open(outfilename, 'w')
    lines = infile.readlines()
    for i in range(0, len(lines), 2):
        outfile.write(lines[i])

    numOfOccurence = 0
    for line in lines:
        for char in line:
            if char == ch:
                numOfOccurence += 1
    
    return numOfOccurence

print(readData('infile.txt', 'outputfile.txt', 'A'))

