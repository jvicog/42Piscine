/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:58:37 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 20:51:57 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	num;

	num = 2;
	if (nb < 2)
		return (0);
	while (num <= nb / 2)
	{
		if (nb % num == 0)
			return (0);
		num++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb < 2147483647 && !ft_is_prime(nb))
		nb++;
	return (nb);
}

/*int main (void)
{
	printf("%d",ft_find_next_prime(7));
}*/