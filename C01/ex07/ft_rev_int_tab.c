/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:49:30 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/06/27 17:42:53 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int	i;
	int	n;

	n = 0;
	i = size;
	while (n != i / 2)
	{
		aux = tab[n];
		tab[n] = tab[size - 1];
		tab[size - 1] = aux;
		size--;
		n++;
	}
}
