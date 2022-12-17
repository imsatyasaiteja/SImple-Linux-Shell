# SImple-Linux-Shell
I've written a C program that works like a Linux Shell

Code Explanation:

        The Main function contains a while loop.
        We need this loop to run the shell() function after execution of each command.

        The shell() function does the following job:
	        It stores the user input in the character array cmd[100] (string).
	        length of this string cmd is stored in l.
        
	        Now, we pass this string cmd and its length l to a token function tok(cmd,l).
		        The tok(cmd, l) function's return type is a 2D array (an array of strings).
		        This function takes the cmd string and tokenizes it into a group of strings.
		        A global variable g is used to store the number of tokens obtained.
                
	        The array of strings returned by token function is stored in a.
	        Now, we compare the first token a[0] given by the user with cd, echo, pwd.
                if the token matches with any one of them, its respective function is called:
		        Cd(a) function uses chdir(a[1]), an in-built function to change the directory.
		        Echo(a) function concats all the tokens from a[1] to a[g-1] and stores in a string b
			        A for loop is used to remove " character. 
		        Pwd() function uses getcwd(), an in-built function to get the current working directory.
		        Cmd(a) function is used to access commands like mkdir, ls, cat, rm, date executables in the bin folder using execvp().
			        In this Cmd(a) function, fork() function is used to initialize a child process.
			        In the child process execvp is used. Its return value is stored in a variable z.
			        If z != 0, It displays an error.
			        execvp takes the input command and the array of strings as arguments.
			        execvp function calls the file from bin folder according to the user input.
			        Meanwhile, the parent process waits for the child process to exit.
                       
	        After leaving the if else loop and executing one of the Cd(), Pwd(), Echo(), Cmd() functions, the array a memory is freed.
        Because we have a while loop in our Main function and it breaks only when character ch != '\n'.
        At each step, it calls the shell() function again.
