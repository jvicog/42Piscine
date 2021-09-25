#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char				*controlPERL(char *argv);
char				*readPERL(char *argv);
char				*firstConditions(char *buf);
char				*secondConditions(char *buf);
char				*thirdConditions(char *buf);
unsigned int		firstSpaceJump(char *buf);
unsigned int		columMatch(char *buf);

char	*controlPERL(char *argv)
{
	char	*buf;

	buf = readPERL(argv);
	if (buf == NULL)
		return (NULL);
	buf = firstConditions(buf);
	if (buf == NULL)
		return (NULL);
	buf = secondConditions(buf);
	if (buf == NULL)
		return (NULL);
	buf = thirdConditions(buf);
	if (buf == NULL)
		return (NULL);
	return (buf);
}

char	*readPERL(char *argv)
{
	int		fd;
	char	*buf;
	ssize_t	n_bytes;

	buf = malloc(sizeof(char) * 5000);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	n_bytes = read(fd, buf, 5000);
	close (fd);
	if (n_bytes == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*firstConditions(char *buf)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < firstSpaceJump(buf) - 3)
	{
		if (buf[i] < 48 || buf[i] > 57)
			return (NULL);
		i++;
	}
	i = 0;
	while (firstSpaceJump(buf) - 3 + i < firstSpaceJump(buf))
	{
		if (buf[i] < 32 || buf[i] > 126)
			return (NULL);
		j = i + 1;
		while (buf[j] != '\n')
		{
			if (buf[i] == buf[j])
				return (NULL);
			j++;
		}	
		i++;
	}
	return (buf);
}

char	*secondConditions(char *buf)
{
	unsigned int	jumpSpaceCount;
	unsigned int	i;

	i = 0;
	jumpSpaceCount = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			jumpSpaceCount++;
		i++;
	}
	if (jumpSpaceCount != (columMatch(buf) + 1))
		return (NULL);
	i = firstSpaceJump(buf);
	while (buf[i] != '\0')
	{
		if (buf[i] != buf[(firstSpaceJump(buf) - 3)]
			&& buf[i] != buf[(firstSpaceJump(buf) - 2)]
			&& buf[i] != buf[firstSpaceJump(buf)])
			return (NULL);
		i++;
	}
	return (buf);
}

char	*thirdConditions(char *buf)
{
	unsigned int	rowLenght;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (buf[i + firstSpaceJump(buf) + 1] != '\n')
		i++;
	rowLenght = i;
	if (rowLenght == 0)
		return (NULL);
	i = firstSpaceJump(buf) + 1;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n' && j != rowLenght)
			return (NULL);
		if (buf[i] == '\n')
			j = 0;
		else
			j++;
		i++;
	}
	return (buf);
}
