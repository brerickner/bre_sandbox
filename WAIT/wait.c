#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int print_string(char *str)
{
	return (write(1, str, strlen(str)));
}
/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		print_string("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		print_string("Oh, it's all better now\n");
	}
	return (0);
}
