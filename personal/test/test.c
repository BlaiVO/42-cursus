#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	n;
	int n2;
	int	i;
	int j;

	if (argc != 2)
		return (0);
	n = atoi(argv[1]);
	n2 = n;
	i = 2;
	j = 0;
	while(j < n / 2 + 1)
	{
		i = 2;
		if (n2 % i == 0)
		{
			j = i;
			printf("%d*", i);
			n2 = n2 / i;
		}
		i++;
	}
}
