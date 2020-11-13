#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int print_string(char *str)
{
	return (write(1, str, strlen(str)));
}
int main (int ac, char **av)
{
	char prompt[] = "$ ";
	char *buffer = " ";
	size_t buffSize = 0;
	(void)ac;

	av[0] = prompt;
	print_string(prompt);
	buffer = malloc(strlen(buffer));
	if (buffer == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}
	free (buffer);
      	getline(&buffer, &buffSize, stdin);
	print_string(buffer);
	free(buffer);
	return (0);
}
