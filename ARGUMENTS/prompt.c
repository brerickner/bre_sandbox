#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int print1(char c)
{
	return (write(1, &c, 1));
}
int print_string(char *str)
{
	return (write(1, str, strlen(str)));
}
int main (int ac, char **av)
{
	char prompt[] = "$ ";
	char *buffer;
	size_t buffSize = strlen(buffer);

	(void)ac;

	av[0] = prompt;
	print_string(prompt);
	buffer = malloc(strlen(buffer));
	if (buffer == NULL)
		write(STDERR_FILENO, "unable to allocate memory", 27);
	getline(&buffer, &buffSize, stdin);
	print_string(buffer);
	
	return (0);
}
