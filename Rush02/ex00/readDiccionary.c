#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	myOwnAtoi(char *str);
int	myDiccionary(char *search);

int	comprobador(char *str, char	*to_find, int booleana, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if ((to_find[j + 1] == '\0') && (str[i + 1] == ' '
					|| str[i + 1] == ':'))
			{
				booleana = 1;
				break ;
			}
			i++;
			j++;
		}
		else
			break ;
	}
	return (booleana);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		booleana;

	i = 0;
	j = 0;
	booleana = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			booleana = comprobador(str, to_find, booleana, i);
			if (booleana == 1)
			{
				return (&str[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int	ft_important_printf(char *str, unsigned int i, int *booleana)
{
	char			aux;
	unsigned int	j;

	aux = str[i];
	j = i;
	if (str[j] == ' ')
	{
		while (str[j] == ' ')
		{
			if (str[j + 1] == '\n')
				*booleana = 1;
			j++;
		}
	}
	if (aux >= 32 && aux < 127 && *booleana == 0)
		write(1, &aux, 1);
	return (*booleana);
}

void	ft_printf(char *str)
{
	unsigned int	i;
	int				booleana;

	booleana = 0;
	i = 0;
	while (str[i] != ':')
	{
		i++;
	}
	i++;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] != '\n')
	{
		booleana = ft_important_printf(str, i, &booleana);
		i++;
	}
}

int	myDiccionary(char *search)
{
	char	*buf;
	char	*c;

	buf = malloc(sizeof(char) * 5000);
	c = ft_strstr(buf, search);
	if (!c)
	{
		free(buf);
		return (-9);
	}
	ft_printf(c);
	free(buf);
	return (0);
}
