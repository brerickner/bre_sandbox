#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main (int ac, char **av)
{
	(void)ac;
	int index;

	for (index = 0; av[index]; index++)
	{
		write(STDOUT_FILENO, av[index], strlen(av[index]));
	}
	return (0);
}
