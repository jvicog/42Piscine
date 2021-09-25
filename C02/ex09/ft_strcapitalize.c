/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:23:02 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:53 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_change2(char *str, int *i)
{
	char	c;

	if (str[*i - 1] > 64 && str[*i - 1] < 91)
	{
		c = str[*i] + 32;
		str[*i] = c;
	}
	else if (str[*i - 1] > 47 && str[*i - 1] < 58)
	{
		c = str[*i] + 32;
		str[*i] = c;
	}
	else if (str[*i - 1] > 96 && str[*i - 1] < 123)
	{
		c = str[*i] + 32;
		str[*i] = c;
	}
	else
	{
		*i = *i + 1;
		return (str);
	}
	*i = *i + 1;
	return (str);
}

char	*ft_change(char *str, int *i)
{
	char	c;

	if (*i == 0 && (str[*i] >= 97 && str[*i] <= 122))
	{
		c = str[*i] - 32;
		str[*i] = c;
		*i = *i + 1;
		return (str);
	}
	else if (str[*i + 1] >= 97 && str[*i + 1] <= 122)
	{
		c = str[*i + 1] - 32;
		str[*i + 1] = c;
		*i = *i + 2;
		return (str);
	}
	*i = *i + 1;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		*pt;

	i = 0;
	pt = &i;
	while (str[i] != '\0')
	{	
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || i == 0)
			str = ft_change(str, pt);
		else if ((str[i] > 90 && str[i] < 97) || str[i] > 122)
			str = ft_change(str, pt);
		else if (str[i] >= 65 && str[i] <= 90)
		{
			str = ft_change2(str, pt);
		}
		else
			i++;
	}
	return (str);
}

/*int		main(void)
{
	char str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	char str2[] = " sALuT, ComMenT tu VAS ? 42Mots QUarante-deUX; cinQuantE+ET+un";

	char empty[] = "";

	printf("\n-----\nBEF = %s", str1);
	printf("\nAFT = %s\n", ft_strcapitalize(str1));
	printf("\nBEF = %s", str2);
	printf("\nAFt = %s\n", ft_strcapitalize(str2));
	printf("\nEmpty = %s\n-----\n", ft_strcapitalize(empty));
}*/