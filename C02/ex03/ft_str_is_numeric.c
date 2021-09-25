/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:48:18 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:44 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		boolean;
	int		i;

	boolean = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
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
	char cadena[]="234324234423445";
	int i;
	i = ft_str_is_numeric(cadena);
	printf("%d", i);
}*/
