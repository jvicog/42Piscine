/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:22:29 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/07 17:04:57 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_hexadecimal(int num)
{
	int		conversor;
	char	aux;

	aux = '0';
	write(1, "\\", 1);
	if (num < 16)
		write(1, &aux, 1);
	while (num != 0)
	{
		conversor = num % 16;
		if (conversor < 10)
			aux = 48 + conversor;
		else
			aux = 87 + conversor;
		write(1, &aux, 1);
		num = num / 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	aux;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			to_hexadecimal(str[i]);
		}
		else
		{
			aux = str[i];
			write(1, &aux, 1);
		}
		i++;
	}
}

/*int		main(void)
{
	char cadena[]="Coucou\ntu vas bien ?";
	ft_putstr_non_printable(cadena);
}*/
