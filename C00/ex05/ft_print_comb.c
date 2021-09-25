/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:16:19 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/06/30 17:58:48 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print (char c, char d, char u, int i)
{
	if (c < d && d < u)
	{
		if (i == 0)
		{
			i = 1;
		}
		else
		{
			write (1, ", ", 2);
		}
		write (1, &c, 1);
		write (1, &d, 1);
		write (1, &u, 1);
	}
	return (i);
}

void	ft_sum (char c, char d, char u)
{
	int	i;

	i = 0;
	while (c != '8')
	{
		i = ft_print(c, d, u, i);
		if (u != '9')
			u++;
		else
		{
			u = '0';
			if (d != '9')
				d++;
			else
			{
				d = '0';
				if (c != '9')
					c++;
			}
		}
	}
}

void	ft_print_comb	(void)
{
	char	c;
	char	d;
	char	u;

	c = '0';
	d = '0';
	u = '0';
	ft_sum(c, d, u);
}
