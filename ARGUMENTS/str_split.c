#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char **tokenizer(char **args, char *deli)
{
	char **token;

	(void)ac;

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");

	}
	return (0);
}
int main (int ac, char **av)
{

//	char *buffer;
//	size_t bufferSize = 32;
//	int 
//	buffer = av[0];
//	getline(&buffer, &bufferSize, stdin);
}
