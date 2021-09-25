/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:55:14 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:45 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
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

	i =  ft_str_is_lowercase(cadena);
	printf("%d", i);
}*/