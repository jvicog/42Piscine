#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	myOwnAtoi(char *str);
int	myDiccionary(char *search);

int	ficheroControl(int argc, char *argv[])
{
	int		fd;
	char	*buf;
	ssize_t	n_bytes;

	buf = malloc(sizeof(char) * 5000);
	if (argc == 2)
		fd = open("numbers.dict.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-4);
	else
	{
		n_bytes = read(fd, buf, 5000);
		close (fd);
		if (n_bytes == 0)
		{
			free(buf);
			write(1, "Dict Error\n", 11);
			return (-5);
		}
	}
	free(buf);
	return (0);
}

int	errorControl(int argc, char *argv[])
{
	unsigned int	i;
	char			*pt;

	if (argc != 2 && argc != 3)
		return (-1);
	i = 0;
	pt = argv[argc - 1];
	while (pt[i] != '\0')
	{
		if (pt[i] < 48 || pt[i] > 57)
		{
			write(1, "Error\n", 6);
			return (-2);
		}
		i++;
	}
	return (0);
}

int	atoiMain(char *str)
{
	unsigned long	res;
	int				i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 4294967295)
	{
		write(1, "Error\n", 6);
		return (-3);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = errorControl(argc, argv);
	if (i != 0)
		return (i);
	i = atoiMain(argv[argc - 1]);
	if (i != 0)
		return (i);
	i = ficheroControl(argc, argv);
	if (i != 0)
		return (i);
	i = myOwnAtoi(argv[argc - 1]);
	if (i != 0)
		return (i);
	return (0);
}
