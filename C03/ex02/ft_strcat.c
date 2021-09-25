/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:43:11 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/08 12:46:22 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
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
	ft_strcat(dest, src);
	printf("result = %s\n-----\n", dest);

	return (0);
}*/