/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:57:27 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 13:10:35 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *str[])
{
	int	i;
	int	j;

	i = 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s2[i] > s1[i])
		{
			flag = -1;
			break ;
		}
		else if (s1[i] > s2 [i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*aux;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				aux = argv[i];
				argv[i] = argv[j];
				argv[j] = aux;
			}
			j++;
		}
		i++;
	}
	ft_print(argv);
}
