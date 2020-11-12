#include <unistd.h>
#include <stdio.h>
#include <string.h>
print1(char c)
{
	return (write(1, &c, 1));
}
int main (int ac, char **av)
{
	(void)ac;
	int index;

	for (index = 0; av[index]; index++)
	{
		write(STDOUT_FILENO, av[index], strlen(av[index]));
		print1(' ');
	}
	print1('\n');
	return (0);
}
