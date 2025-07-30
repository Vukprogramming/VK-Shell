# VK Shell
VK Shell is a shell program i wrote in C
i started this project to get to know C better
this project was started on the 21/7/2025
this project is still unfinished

**The current commands are:**
* Echo: prints out any string you input
* get/osInfo: Prints out what OS you are currently using
* help: prints out all the commands and what they do
* crls: Clears the screen using ANSI escape codes (may not work in windows cmd if you didnt set up ANSI escape codes)
* add: Adds two numbers
* sub: Subtracts two numbers
* mul: Multiplies two numbers
* div: Divides two numbers
* chuser: Changes the user's username
* chpass -c: Changes the user's password
**Default username is: "X" | Default password is "VKSHELL" (You'll need the password to run certain commands)**
* echo aui: Prints all user information (Username and password)
* strlen: Lets you input a string and tell you the length of that strings
* crt: Creates a file
* wrt: Writes to a file (add -a to apend content to the file | add -a -nl if you want you want you apend content on a new line)
* rd: Command to read and print the contents of a file
* rm: Removes a file
* mkdir: Makes a directory
* rmdir: Removes a directory (can only remove empty directories **for now**)

**NOTE: I'll add adding files to certain directories and removing directories with file in them in the next commit**

## How to run
You currently have 2 ways to run it
* (Linux) Use the Makefile and compile it into a binary and run it using the command "./vk"
* (Windows) You can cd into the VK Shell's directory and run the command "gcc -Wall -Wextra -std=c11 -o vk vk.c src/basic_cmds/cmds.c src/userVar.c src/calc_cmds/calc.c  src/file_cmds/file_io.c  src/user_cmds/user.c" to compile it into a .exe and run it