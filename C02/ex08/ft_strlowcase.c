/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:09:23 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:50 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			c = str[i] + 32;
			str[i] = c;
		}
		i++;
	}
	return (str);
}

/*int main (void)
{
	char cadena[] = "ASASASAa2234324454325";
	int i = 0;

	printf("%s", ft_strlowcase(cadena));
	//printf ("%c", cadena);
	
}*/