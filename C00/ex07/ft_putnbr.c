/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:08:07 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/06/30 17:59:00 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr (int nb)
{
	char	imp;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb <= 9)
	{
		imp = 48 + nb;
		write(1, &imp, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		imp = 48 + (nb % 10);
		write(1, &imp, 1);
	}
}
