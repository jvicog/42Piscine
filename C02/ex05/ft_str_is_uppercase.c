/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:31:05 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:47 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
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
	char cadena[]="EYYYaYY";
	int i;

	i =  ft_str_is_uppercase(cadena);
	printf("%d", i);
}*/