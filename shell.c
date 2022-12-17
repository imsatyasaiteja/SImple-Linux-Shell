#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<wait.h>

void Cmd(char **a);
void shell();
char **tok(char *cmd, int l);
void Echo(char **a);
char *Pwd();
void Cd(char **a);

int g;
extern char **environ;

// Main function
void main()
{	
	system("clear");
	char ch = '\n';
	
	printf("\n\n\n*********************** SIMPLE SHELL *********************** \n");
	
	while(1)	
	{
		if(ch == '\n')
		{ 
			shell();
		}
		else
		{
			break;
		}
		ch = getchar();	
	}		
}

// Shell function that takes user input
void shell()
{
	char cmd[100];
	char **a;
	char *c = Pwd();
	
	printf("\n\nSimpleShell:(%s)$ ",c);
	scanf("%[^\n]s",cmd);
		
	int l = strlen(cmd);
	a = tok(cmd, l);

	if(strcmp("cd", a[0]) == 0)
	{
	 	Cd(a);
	}
	else if(strcmp("echo", a[0]) == 0)
	{
		Echo(a);
	}
	else if(strcmp("pwd", a[0]) == 0 && a[1] == NULL)
	{
		c = Pwd();
		printf("%s\n",c);
	}
	else
	{	
		Cmd(a);
	}

	printf("\n\n************************************************************* \n");
	free(a);
}

// Command function
void Cmd(char **a)
{
	int status;
	int cpid = fork();
   	char *cmd = a[0];
   	
	if(cpid == 0)
	{	
		int z = execvp(cmd, a);
		if(z != 0)
		{
			perror("Error ");
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}	
}

// Token function
char **tok(char *cmd, int l)
{
	char delim[] = " ";
	char **token = malloc(l*sizeof(char *));
	g = 0;
		
	token[g] = strtok(cmd, delim);
		
	while(token[g] != 0)
	{	
		g++;
		token[g] = strtok(0, delim);	 
	}

	return token;
}	

// Echo function
void Echo(char **a)
{
	char b[100] = "";
	
	for(int i=1; i<g; i++)
	{
		strcat(b, a[i]);
		strcat(b, " ");
	}
	
	int k = strlen(b);
	
	for(int i=0; i<k; i++)
	{
		if(b[i] == '"')
		{
			for(int j=i; j<k; j++)
			{
				b[j] = b[j+1];
			}
		}
	}
	
	printf("%s\n",b);	
}

// Pwd function
char *Pwd()
{	
	char *c = malloc(100*sizeof(char *));
	getcwd(c, 100);	
	return c;
}

// Cd function
void Cd(char **a)
{	
	char *t;
	
	if(a[1] == NULL || strcmp(a[1], "~") == 0)
	{
		chdir(getenv("HOME"));
	}
	else
	{	
		chdir(a[1]);
		t = Pwd();
		printf("directory changed to %s\n",t);
	}	
}
