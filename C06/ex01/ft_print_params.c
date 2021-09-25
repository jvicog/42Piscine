/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:02:37 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 13:09:10 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	length_param (char *argv[])
{
	int	i;

	i = 0;
	while (argv[0][i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i != argc)
	{
		write (1, argv[i], length_param(&argv[i]));
		write (1, "\n", 1);
		i++;
	}
}
