/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:07:14 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/14 12:47:46 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (0);
	while (i < (nb / 2))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
int main (void)
{
	printf("%d",ft_is_prime(104729));
}*/