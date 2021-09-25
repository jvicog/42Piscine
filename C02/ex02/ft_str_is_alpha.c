/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:32:11 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:43 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	boolean;
	int	i;

	boolean = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 123)
		{
			if (str[i] > 90 && str[i] < 97)
			{
				boolean = 0;
				return (boolean);
			}
		}
		else
		{
			boolean = 0;
			return (boolean);
		}
		i++;
	}
	return (boolean);
}

/*int  main (void)
{
	char cadena[] = "holaa";
	int i;

	i = ft_str_is_alpha(cadena);
	printf("%d", i);
}*/
