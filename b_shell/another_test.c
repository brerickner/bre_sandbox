#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char **tokenizer(char *str, char *delim)
{
	char **buffer;
	int delim_count = 0, i, token_count;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == *delim)
			delim_count++;
	}

	token_count = delim_count + 1;

	buffer = malloc(sizeof(char *) * (token_count + 1));

	if (buffer == NULL)
	{       return (NULL);  }

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
	int gl, i;
	(void)ac;


	av[0] = prompt;
	print_string(prompt);
	gl = getline(&buffer, &buffSize, stdin);

	if (gl == -1)
		print_string("could not read line");
	else
	{
		tokens = tokenizer(buffer, " ");
		for (i = 0; tokens[i]; i++)
		{
			print_string(tokens[i]);
			print_string("\n");
		}
		free(tokens);
		free(buffer);
	}

	return (0);
}
