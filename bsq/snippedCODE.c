unsigned int	firstSpaceJump(char *buf)
{
	unsigned int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

unsigned int	columMatch(char *buf)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (i < firstSpaceJump(buf) - 3)
	{
		res = res * 10 + buf[i] - '0';
		i++;
	}
	return (res);
}

unsigned int	get_pos_tab(unsigned int row, unsigned int column,
								char *buf, unsigned int rowWeight)
{
	unsigned int	i;

	i = column * (rowWeight + 1) + row + firstSpaceJump(buf) + 1;
	return (i);
}

unsigned int	rowWeight(char *buf)
{
	unsigned int	i;

	i = 0;
	while (buf[i + firstSpaceJump(buf) + 1] != '\n')
	{
		i++;
	}
	return (i);
}
