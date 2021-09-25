/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:36:15 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/14 12:42:04 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive(int nb)
{
	int	a;

	a = -1;
	if (nb < 101)
		while (++a < 12)
			if (a * a > nb)
				return (a - 1);
	if (nb > 100)
		while (++a < 10)
			if (((2 * ft_recursive(nb / 100) * 10 + a) * a > nb
					- 100 * ft_recursive(nb / 100) * ft_recursive(nb / 100)))
				return (ft_recursive(nb / 100) * 10 + (a - 1));
	return (ft_recursive(nb / 100) * 10 + (a - 1));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = ft_recursive(nb);
	if (i * i == nb)
		return (i);
	return (0);
}

/*int main (void)
{
	printf("%d",ft_sqrt(121));
}*/