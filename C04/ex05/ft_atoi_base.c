/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:45:59 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 18:52:46 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	baseCode(long num_long, int	*j, int base, char	*array)
{
	char	aux;
	long	conversor;

	while (num_long != 0)
	{
		conversor = num_long % base;
		if (conversor < 10)
			aux = 48 + conversor;
		else
			aux = 87 + conversor;
		array[*j] = aux;
		num_long = num_long / base;
		*j = *j - 1;
	}
}

int	changeBase(int num, int base, int signo)
{
	char			array[100];
	int				j;
	long			num_long;

	num_long = num * signo;
	j = 100;
	baseCode(num_long, &j, base, array);
	num = 0;
	while (array[j + 1] > 47 && array[j + 1] < 58)
	{
		num = num * 10 + array[j + 1] - '0';
		j++;
	}
	if (num_long == -2147483648)
		num = num_long;
	return (num * signo);
}

int	controlError(char *base)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	int				signo;

	signo = 1;
	i = 0;
	if (controlError(base))
		return (0);
	while (base[i] != '\0')
		i++;
	if (nbr < 0)
		signo = -1;
	return (changeBase(nbr, i, signo));
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	int				signo;
	int				numero;

	numero = 0;
	i = 0;
	signo = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			signo = signo * -1;
		if (str[i] > 47 && str[i] < 58)
			break ;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		numero = numero * 10 + str[i] - '0';
		i++;
	}
	if (signo == -1 && numero != 0)
		numero = numero * -1;
	if (numero > 2147483647 || numero < -2147483648)
		return (-1);
	return (ft_putnbr_base(numero, base));
}

/*int main(void)
{
	int	i;

	i = ft_atoi_base("-2147483648", "0123456789");
	printf("%d", i);
}*/
