/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:38:44 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/06/30 13:45:47 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_imp(int *arr, int n)
{
	int	i;
	int	c;

	i = 1;
	c = 1;
	while (i < n)
	{
		if (arr[i - 1] >= arr[i])
			c = 0;
		i++;
	}
	if (c != 0)
	{
		i = 0;
		while (i < n)
			ft_putchar(arr[i++] + 48);
		if (arr[0] < (10 - n))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	cadena[9];

	i = 0;
	while (i < n)
		cadena[i++] = 0;
	while (cadena[0] <= (10 - n))
	{
		ft_imp(cadena, n);
		cadena[n - 1]++;
		i = n;
		while (i != 0 && n > 1)
		{
			i--;
			if (cadena[i] > 9)
			{
				cadena[i - 1]++;
				cadena[i] = 0;
			}
		}
	}	
}
