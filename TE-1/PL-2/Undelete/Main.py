from __future__ import print_function
import os

def main():
    print('''
1. Recover deleted file
2. Exit
''')
    ch = int(raw_input('Enter your choice: '))
    if ch == 1:    
        part = raw_input('Enter partition path: ')
        os.system('sudo ntfsundelete %s -t 2d' % part)        
        inode = raw_input('Enter inode number: ')
        output = raw_input('Enter the output file name: ')
        os.system('sudo ntfsundelete %s -u -i %s -o %s' % (part, inode, '~/recovered/' + output))
        os.system('sudo chown student ~/recovered/*')
        print('Recovered file is stored at: %s' % '~/recovered/' + output)
        print('Contents of the file are: \n%s' % open('/home/student/recovered/' + output).read())
    if ch == 2:
        quit()

if __name__ == '__main__':
    while True:    
        main()    
    
