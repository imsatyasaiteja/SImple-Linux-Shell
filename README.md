# Simple Linux Shell

I've written a C program that works like a Linux Shell

## Code Explanation :

- The Main function contains a while loop.
We need this loop to run the function after execution of each command.

- The shell function does the following job :
	1) It stores the user input in the character array cmd[100] (string).
	2) length of this string cmd is stored in l.
        
- We pass this string cmd and its length l to a token function tok(cmd,l).
- The tok(cmd, l) function's return type is a 2D array (an array of strings).
	1) This function takes the cmd string and tokenizes it into a group of strings.
	2) A global variable g is used to store the number of tokens obtained.
- The array of strings returned by token function is stored in a.
- Now, we compare the first token a[0] given by the user with cd, echo, pwd. if the token matches with any one of them, its respective function is called :
	1) Cd(a) function uses chdir(a[1]), an in-built function to change the directory.
	2) Echo(a) function concats all the tokens from a[1] to a[g-1] and stores in a string b
	3) A for loop is used to remove " character. 
	4) Pwd() function uses getcwd(), an in-built function to get the current working directory.
	5) Cmd(a) function is used to access commands like mkdir, ls, cat, rm, date executables in the bin folder using execvp().
		- In this Cmd(a) function, fork() function is used to initialize a child process.
		- In the child process execvp is used. Its return value is stored in a variable z.
		- If z != 0, It displays an error.
		- execvp takes the input command and the array of strings as arguments.
		- execvp function calls the file from bin folder according to the user input.
		- Meanwhile, the parent process waits for the child process to exit.
                       
- After leaving the if else loop and executing one of the Cd(), Pwd(), Echo(), Cmd() functions, the array a memory is freed.
- Because we have a while loop in our Main function and it breaks only when character ch != '\n'.
- At each step, it calls the shell function again.


## Output Images :


### cat, date commands

![cat,date](https://user-images.githubusercontent.com/85508314/208363790-8ec1230a-253c-447b-a0a1-66e264c731a4.png)


### cd command

![cd](https://user-images.githubusercontent.com/85508314/208364013-62668cbb-6f9d-4f6f-aec1-f04ea5f400e7.png)


### echo, pwd commands

![echo,pwd](https://user-images.githubusercontent.com/85508314/208364073-0e444897-ff37-4a09-a9bd-64215e55bee3.png)


### ls command

![ls](https://user-images.githubusercontent.com/85508314/208364117-bb895734-e684-4b37-8394-8bc78c81ebb5.png)


### mkdir command

![mkdir](https://user-images.githubusercontent.com/85508314/208364161-f1ff1fb9-ee89-4c80-9871-3b4d4e9802d5.png)


### rm command

![rm](https://user-images.githubusercontent.com/85508314/208364190-c3c16281-7eef-4a7e-acea-2c5a41a1d9bf.png)

