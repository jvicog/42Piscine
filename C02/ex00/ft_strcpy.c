/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:27:21 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:40 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int		main (void)
{
	char src[4]="HOLA";
	char *desr;
	int i = 0;

	desr = ft_strcpy(desr, src);
	while(desr [i] != '\0')
	{
		printf("%c", desr[i]);
		i++;
	}
}*/