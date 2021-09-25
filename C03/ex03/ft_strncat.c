/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:14 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/12 16:55:07 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < nb && (src[j] != '\0' || dest[i] != '\0'))
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main(void)
{
	char dest[20] = "Hello";
	char src[] = ", world!";

	printf("-----\ndest = %s\nsrc = %s\n", dest, src);
	ft_strncat(dest, src, 4);
	printf("result = %s\n-----\n", dest);

	return (0);
}*/