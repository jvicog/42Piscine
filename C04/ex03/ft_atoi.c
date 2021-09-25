/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:18:40 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 20:09:06 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_num (char *str, int i)
{
	int	cont;

	cont = 0;
	while ((str[i] > 47 && str[i] < 58))
	{
		cont = cont * 10 + (str[i] - '0');
		i++;
	}
	return (cont);
}

int	ft_atoi(char *str)
{
	int	i;
	int	contneg;
	int	start;
	int	cont;
	int	neg;

	i = 0;
	contneg = 0;
	neg = 1;
	cont = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		 || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			contneg++;
		i++;
	}
	start = i;
	if (contneg % 2 == 1)
		neg = neg * -1;
	cont = ft_num(str, start);
	return (cont * neg);
}

/*int	main(void)
{
	char	*str;

	str = "234234";
	printf("%d\n", ft_atoi(str));
}*/
