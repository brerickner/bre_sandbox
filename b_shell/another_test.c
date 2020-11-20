#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char **tokenizer(char *str, char *delim)
{
	char **buffer = NULL;
	int delim_count = 0, i, token_count;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == *delim)
			delim_count++;
	}

	token_count = delim_count + 1;

	buffer = malloc(sizeof(char *) * (token_count + 1));

	if (buffer == NULL)
		return (NULL);
	i = 0;
	buffer[i] = strtok(str, delim);
	i++;

	while (i < token_count)
	{
		buffer[i] = strtok(NULL, delim);
		i++;
	}

	buffer[i] = NULL;

	return (buffer);
}

int main(int ac, char **av)
{
	char prompt[] = "$ ";
	char *buffer = NULL;
	char **tokens = NULL;
	size_t buffSize = 0;
	char *cpyBuff = NULL;
	int gl, i;
	(void)ac;

	while(1)
	{
		av[0] = prompt;
		print_string(prompt);

		if (getline(&buffer, &buffSize, stdin) == -1)
			break; /*need to write error message*/

		cpyBuff = _strdup(buffer);
		tokens = tokenizer(cpyBuff,"\n");
		if (execve(tokens[0], tokens, NULL) == -1)
			break; /*needs error message*/
	}
	free(buffer);
	return (0);
}
