/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:57:18 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/14 12:44:41 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	cont;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	cont = nb;
	while (nb > 1)
	{
		cont = (nb - 1) * cont;
		nb--;
	}
	return (cont);
}
/*
int main (void)
{
	printf("%d", ft_iterative_factorial(5));
}
*/