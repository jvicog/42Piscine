#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char			*controlPERL(char *argv);
int				main(int argc, char *argv[]);
int				errorControl(int argc, char *argv[]);
void			printMap(char *buf);
unsigned int	firstSpaceJump(char *buf);
void			*setSQUARE(char *buf);
void			standard_map(void);
void			control(char *buf);

int	main(int argc, char *argv[])
{
	int		i;
	char	*buf;

	i = 1;
	while (i < argc)
	{
		buf = controlPERL(argv[i]);
		control(buf);
		i++;
	}
	if (argc < 2)
	{
		standard_map();
		buf = controlPERL("standardFile.txt");
		control(buf);
	}
	free(buf);
}

void	control(char *buf)
{
	if (buf == NULL)
		write(1, "map error\n", 10);
	else
	{
		setSQUARE(buf);
		printMap(buf);
		write(1, "\n", 1);
	}
}

void	printMap(char *buf)
{
	unsigned int	i;
	char			aux;

	i = firstSpaceJump(buf) + 1;
	while (buf[i] != '\0')
	{
		aux = buf[i];
		write(1, &aux, 1);
		i++;
	}
}

void	standard_map(void)
{
	char	buf;
	int		fd;

	fd = open("standardFile.txt", O_WRONLY | O_TRUNC | O_CREAT, 00700);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
}
