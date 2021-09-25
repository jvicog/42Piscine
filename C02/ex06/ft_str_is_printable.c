/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:37:16 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:48 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			boolean = 0;
			return (boolean);
		}
		i++;
	}
	return (boolean);
}

/*int main (void)
{
	char cadena[]="hola";
	int i;

	i =  ft_str_is_printable(cadena);
	printf("%d", i);
}*/