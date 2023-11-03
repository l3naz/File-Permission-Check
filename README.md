# File-Permission-Check
C program that checks and reports the file permissions of a specified file or directory. This program will use system calls to obtain and display the file permissions in a human-readable format.

File Permission Checker
This is a simple C program to check and display the permissions of a file or directory.

Usage
When run, the program will prompt for a file/directory path. It will then output the octal permission bits and break down the owner, group, and other permissions.

Example:

Enter file path or directory path: /usr/local/file.txt 

File Permissions: 644

Owner Permissions: 6
Group Permissions: 4 
Others Permissions: 4

The owner, group, and other permissions are displayed in a more human-readable rwx format:

r = read
w = write
x = execute

So 644 would mean:
Owner can read and write
Group can read
Others can read

Explanation
The program uses the stat() system call to get information about the file. It extracts the permission bits from the st_mode field of the stat struct.

The permissions are bitmasked with S_IRWXU, S_IRWXG, and S_IRWXO to isolate the owner/group/other bits.

Building
To build: gcc -o fileperms fileperms.c

Contributing
Contributions welcome! This is a simple program but suggestions for improvements are appreciated.
