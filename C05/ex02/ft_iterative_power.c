/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:24:43 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/14 12:43:39 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	count;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	count = nb;
	while (power > 1)
	{
		count = count * nb;
		power--;
	}
	return (count);
}

/*
int main (void)
{
	printf("%d", ft_iterative_power(4, 8));
}*/