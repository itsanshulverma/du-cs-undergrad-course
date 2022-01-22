'''
14. Write a function that reads a file file1 and copies only alternative lines to another file file2. 
Alternative lines copied should be the odd numbered lines. Use Exception.
Author : Anshul Verma (19/78065)
'''

def  copyOddNumberedLines(file_in, file_out):
    print("\nCopying alternate lines from \'{}\' to \'{}\'...".format(file_in, file_out))
    try:
        fh_in = open(file_in, 'r')
        fh_out = open(file_out, 'w')
        lines = fh_in.readlines()
        for i in range(0, len(lines), 2):
            fh_out.write(lines[i])
        print('Done!\n')
    except FileNotFoundError:
        print('Error: \'{}\' not found.\n'.format(file_in))

if __name__ == "__main__":

    copyOddNumberedLines('file1.txt', 'file2.txt')