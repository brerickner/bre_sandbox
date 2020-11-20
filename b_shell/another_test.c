#include "shell_header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char **token_input(void)
{
	size_t buffSize = 0;
	char *cpyBuff = NULL;
	char *buffer = NULL;

	if (getline(&buffer, &buffSize, stdin) == -1)
		exit(-1); /*need to write error message*/
	cpyBuff = _strdup(buffer);
	free(buffer);
	return(tokenizer(cpyBuff,"\n"));
}
int main(int ac, char **av)
{
	char *buffer = NULL;
	char **tokens = NULL;
	size_t buffSize = 0;
	char *cpyBuff = NULL;
	(void)ac;

	while(1)
	{
		prompt();
//		if (getline(&buffer, &buffSize, stdin) == -1)
//			break; /*need to write error message*/
//
//		cpyBuff = _strdup(buffer);
		tokens = token_input();
		if (execve(tokens[0], tokens, NULL) == -1)
			break; /*needs error message*/
	}
//	free(buffer);
	return (0);
}
