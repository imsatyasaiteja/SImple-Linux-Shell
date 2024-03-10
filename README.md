## Simple Linux Shell

Hey! Here's a Command Line Interface application I've written in C language that works like a Linux shell

### Code Explanation
- The _main( )_ function executes a _while_ loop
We need this loop to run the shell input command infinitely after execution of each command
- The _shell_ function does the following job :
  - It stores the user input in the character array _cmd[100]_ (string)
  - length of this string _cmd_ is stored in _l_
- We pass this string cmd and its length _l_ to a token function _tok(cmd,l)_
- The _tok(cmd, l)_ function's return type is a 2D array (an array of strings)
  - This function takes the _cmd_ string and tokenizes it into a group of strings
  - A global variable _g_ is used to store the number of tokens obtained
- The array of strings returned by token function is stored in _a_
- Now, we compare the first token _a[0]_ given by the user with _cd, echo, pwd_, If the token matches with any one of them, its respective function is called :
  - _Cd(a)_ function uses _chdir(a[1])_, an in-built function to change the directory
  - _Echo(a)_ function concats all the tokens from _a[1]_ to _a[g-1]_ and stores in a string _b_
  - A _for_ loop is used to remove _"_ character
  - _Pwd( )_ function uses _getcwd( )_, an in-built function to get the current working directory
  - _Cmd(a)_ function is used to access commands like _mkdir, ls, cat, rm, date_ executables in the bin folder using **_execvp( )_**
	- In this _Cmd(a)_ function, **_fork( )_** function is used to initialize a child process
	- In the child process execvp is used. Its return value is stored in a variable z
	- If _z != 0_, It displays an error
	- _execvp_ takes the input command and the array of strings as arguments
	- _execvp_ function calls the file from bin folder according to the user input
	- Meanwhile, the parent process waits for the child process to exit             
- After leaving the _if-else_ loop and executing one of the _Cd( ), Pwd( ), Echo( ), Cmd( )_ functions, the array a memory is freed
- Because we have a _while_ loop in our Main function and it breaks only when character _ch != '\n'_
- At each step, it calls the shell function again

### Preview
Here are some important Linux commands that I've tested on my Linux shell application

<img src="https://github.com/imsatyasaiteja/Simple-Linux-Shell/assets/85508314/8098031e-be1a-43c3-9c99-f32f6dfb04be" width="400" alt="commands_1">
<img src="https://github.com/imsatyasaiteja/Simple-Linux-Shell/assets/85508314/daac292d-25e7-4e2f-be2b-538baca8a945" width="400" alt="commands_2">
