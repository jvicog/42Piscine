#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	myOwnAtoi(char *str);
int	myDiccionary(char *search);

int	spaceFunc(int space)
{
	if (space == 0)
		space = 1;
	else
		write(1, " ", 1);
	return (space);
}

void	elevenCase(char *str, unsigned int *aux)
{
	char			numerosOnceDiecinueve[3];

	numerosOnceDiecinueve[0] = str[*aux];
	numerosOnceDiecinueve[1] = str[*aux + 1];
	numerosOnceDiecinueve[2] = '\0';
	myDiccionary(numerosOnceDiecinueve);
}

char	*allZeros(char *str, unsigned int total, unsigned int aux)
{
	char			*numero_otro;
	unsigned int	j;

	j = 0;
	numero_otro = (char *) malloc(sizeof(char) * (total));
	while (j <= (total))
	{
		numero_otro[j] = '\0';
		j++;
	}
	j = 0;
	while (j < (total))
	{
		numero_otro[j] = '0';
		numero_otro[0] = str[aux];
		j++;
	}
	return (numero_otro);
}

void	singleNumber(char *str, unsigned int total)
{	
	char	*numero_segundo;

	if (*str != 0 && ((total) >= 3))
	{
		numero_segundo = (char *) malloc(sizeof(char));
		numero_segundo[0] = *str;
		myDiccionary(numero_segundo);
		*str = '1';
		write(1, " ", 1);
		free(numero_segundo);
	}
}
