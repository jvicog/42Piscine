/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:06:27 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/08 19:46:42 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	comprobador(char *str, char	*to_find, int booleana, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				booleana = 1;
				break ;
			}
			i++;
			j++;
		}
		else
			break ;
	}
	return (booleana);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		booleana;

	i = 0;
	j = 0;
	booleana = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			booleana = comprobador(str, to_find, booleana, i);
			if (booleana == 1)
			{
				return (&str[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/*int		main(void)
{
	char str[] = "3434343434564";
	char to_find[] = "";

	printf("-----\nstr = %s\nto_find = %s\n", str, to_find);
	printf("%s\n", ft_strstr(str, to_find));

	return (0);
}*/
