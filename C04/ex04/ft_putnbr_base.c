/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:44:02 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 20:09:13 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *array, int j)
{
	char			aux;

	while (array[j] != '\0')
	{
		aux = array[j];
		write(1, &aux, 1);
		j++;
	}
}

void	to_hexadecimal(int num, int base)
{
	long	conversor;
	char	aux;
	char	array[100];
	int		j;

	j = 100;
	while (num != 0)
	{
		conversor = num % base;
		if (conversor < 10)
			aux = 48 + conversor;
		else
			aux = 87 + conversor;
		array[j] = aux;
		num = num / base;
		j--;
	}
	ft_print(array, j + 1);
}

void	to_hexadecimal2(int num, int base)
{
	long	conversor;
	char	aux;
	char	array[100];
	int		j;
	long	num_long;

	num_long = num;
	write(1, "-", 1);
	num_long = num_long * -1;
	j = 100;
	while (num_long != 0)
	{
		conversor = num_long % base;
		if (conversor < 10)
			aux = 48 + conversor;
		else
			aux = 87 + conversor;
		array[j] = aux;
		num_long = num_long / base;
		j--;
	}
	ft_print(array, j + 1);
}

int	controlError(char *base)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;

	i = 0;
	if (controlError(base))
		return ;
	while (base[i] != '\0')
	{
		i++;
	}
	if (nbr == -2147483648)
		to_hexadecimal2(nbr, i);
	else
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			write(1, "-", 1);
		}
		to_hexadecimal(nbr, i);
	}
}

/*int	main(void)
{
	ft_putnbr_base(345, "0123456789ABCDEF");
}*/
