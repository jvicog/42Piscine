/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:17:07 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/15 13:09:48 by jvico-ga         ###   ########.fr       */
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
	while (argc > 1)
	{
		write (1, argv[argc - 1], length_param(&argv[argc - 1]));
		write (1, "\n", 1);
		argc--;
	}
}
