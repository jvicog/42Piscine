#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		myDiccionary(char *search);
char	*excepcionalCase(unsigned int *aux, unsigned int i, char *str);
int		recursiveFunction(char *str);
int		smallNumbers(char *str, unsigned int *aux, unsigned int i, int *space);
int		importantCode(char *str, unsigned int i, unsigned int *aux, int *space);
int		myOwnAtoi(char *str);
int		spaceFunc(int space);
void	elevenCase(char *str, unsigned int *aux);
char	*allZeros(char *str, unsigned int total, unsigned int aux);
void	singleNumber(char *str, unsigned int total);

char	*excepcionalCase(unsigned int *aux, unsigned int i, char *str)
{
	char			*numero_primero;
	unsigned int	j;

	j = 0;
	numero_primero = (char *) malloc(sizeof(char) * (i - *aux - 1) % 3);
	while (j <= ((i - *aux - 1) % 3))
	{
		numero_primero[j] = str[*aux + j];
		j++;
	}
	*aux = *aux + ((i - *aux - 1) % 3 - 1);
	return (numero_primero);
}

int	recursiveFunction(char *str)
{
	unsigned int	i;
	unsigned int	aux;
	int				k;
	int				space;

	space = 0;
	aux = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (aux < i - 1)
	{
		if (str[aux] != '0')
		{
			k = importantCode(str, i, &aux, &space);
			if (k < 0)
				return (k);
		}
		aux++;
	}
	return (0);
}

int	smallNumbers(char *str, unsigned int *aux, unsigned int i, int *space)
{
	char	*numero;
	int		k;

	k = 0;
	if ((str[*aux] == '1') && (str[*aux + 1] != '0') && ((i - *aux) == 2))
		elevenCase(str, aux);
	else
	{
		if ((i - *aux - 1) % 3 == 0 && *aux != 0 && str[*aux - 1] == '1')
		{
			*space = 0;
			numero = allZeros(str, (i - *aux), *aux);
		}
		else
		{
			singleNumber(&str[*aux], (i - *aux));
			numero = allZeros(str, (i - *aux), *aux);
			k = myDiccionary(numero);
		}
	}
	if (k != 0)
		free(numero);
	return (k);
}

int	importantCode(char *str, unsigned int i, unsigned int *aux, int *space)
{
	char			*numero_primero;
	int				k;

	k = 0;
	*space = spaceFunc(*space);
	if ((i - *aux - 1) % 3 != 0 && (i - *aux > 3))
	{
		numero_primero = excepcionalCase(aux, i, str);
		recursiveFunction(numero_primero);
	}
	else
	{
		k = smallNumbers(str, aux, i, space);
	}
	return (k);
}

int	myOwnAtoi(char *str)
{
	unsigned int	i;
	unsigned int	aux;
	int				space;
	int				k;

	space = 0;
	aux = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (aux < i)
	{
		if (str[aux] != '0')
		{
			k = importantCode(str, i, &aux, &space);
			if (k < 0)
			{
				write(1, "Dict Error\n", 11);
				return (k);
			}
		}
		aux++;
	}
	write(1, "\n", 1);
	return (0);
}
