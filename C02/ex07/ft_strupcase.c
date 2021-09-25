/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:47:31 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:49 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			c = str[i] - 32;
			str[i] = c;
		}
		i++;
	}
	return (str);
}

/*int main (void)
{
	char cadena[] = "hola2234324454325";
	int i = 0;

	printf("%s", ft_strupcase(cadena));
	//printf ("%c", cadena);
	
}*/