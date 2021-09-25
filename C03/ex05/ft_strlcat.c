/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:56:43 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/08 19:39:05 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_ayuda(char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dst;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaing;

	dst = dest;
	src_start = src;
	remaing = size;
	while (remaing-- != 0 && *dst != '\0')
		dst++;
	dst_length = dst - dest;
	remaing = size - dst_length;
	if (remaing == 0)
		return (dst_length + ft_ayuda(src));
	while (*src != '\0')
	{
		if (remaing > 1)
		{
			*dst++ = *src;
			remaing--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + (src - src_start));
}

/*int main(void)
{
	char dest[20] = "1234";
	char pepo[20] = "1234";
	char src[] = "567824";
	char pepa[] = "567824";
	unsigned int size = 10;
	unsigned int result;
	
	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
	result = ft_strlcat(dest, src, size);
	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);

		printf("-----\npepo = %s\npepa = %s\nnb = %d\n\n", pepo, pepa, size);
	result = strlcat(pepo, pepa, size);
	printf("pepo (cat) = %s\nresult = %d\n-----\n", pepo, result);
	return (0);
}*/