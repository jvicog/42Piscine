/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:28:49 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/06/30 17:58:53 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sum (char *n11, char *n12, char *n21, char *n22)
{
	if (*n22 == '9' && *n21 == '9')
	{
		if (*n12 != '9')
			*n12 = *n12 + 1;
		else
		{
			*n12 = '0';
			*n11 = *n11 + 1;
		}
	}
	if (*n22 != '9')
		*n22 = *n22 + 1;
	else
	{
		*n22 = '0';
		if (*n21 != '9')
			*n21 = *n21 + 1;
		else
			*n21 = '0';
	}
}

int	ft_checker (int i)
{
	if (i == 0)
	{
		i = 1;
	}
	else
	{
		write(1, ", ", 2);
	}
	return (i);
}

void	ft_printf (char n11, char n12, char n21, char n22)
{
	write(1, &n11, 1);
	write(1, &n12, 1);
	write(1, " ", 1);
	write(1, &n21, 1);
	write(1, &n22, 1);
}

void	ft_print_comb2 (void)
{
	char	n11;
	char	n12;
	char	n21;
	char	n22;
	int		i;

	n11 = '0';
	n12 = '0';
	n21 = '0';
	n22 = '0';
	i = 0;
	while (n11 <= '9')
	{
		if (n11 < n21 || ((n11 == n21) && (n12 < n22)))
		{
			i = ft_checker(i);
			ft_printf (n11, n12, n21, n22);
		}
		ft_sum(&n11, &n12, &n21, &n22);
	}
}
