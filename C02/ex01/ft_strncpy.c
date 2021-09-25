/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:56:29 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:42 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			aux;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		aux = src[i];
		dest[i] = aux;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int		main(void)
{
	char src[4]="HOLA";
	char *dest;
	int i;

	i = 0;
	dest = ft_strncpy(dest, src, 5);
	while (dest[i] != '\0')
	{
		printf("%c", dest[i]);
		i++;
	}
}*/
