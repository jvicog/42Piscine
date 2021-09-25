/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01backtracking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:58:42 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/04 21:16:08 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	solver (int *tablero, int row, int col);

void	imprimir_tablero(int *tablero)
{
	int		i;
	char	aux;

	i = 0;
	while (i < 16)
	{
		aux = tablero[i] + '0';
		write(1, &aux, 1);
		if ((i + 1) % 4 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int	*generar_tablero(int i)
{
	int		*tablero;
	int		j;

	j = 0;
	if (i == 31)
		tablero = malloc((sizeof(int) * (i / 2) + 1));
	else
		tablero = malloc((sizeof(int) * (i / 2) + 1));
	while (j < ((i / 2) + 1))
	{
		tablero[j] = 0;
		j++;
	}
	return (tablero);
}

int	ft_comprobar_parametro(char *pt)
{
	int	i;

	i = 0;
	while (pt[i] != '\0')
	{
		if (pt[i] > 48 && pt[i] < 53)
		{
			if (pt[i + 1] == ' ' || pt[i + 1] == '\0')
			{
				if (pt[i + 1] == '\0')
					i++;
				else
					i = i + 2;
			}
			else
				break ;
		}
		else
			break ;
	}
	return (i);
}

int	get_pos_tab(int x, int y)
{
	return (((y - 1) * 4) + (x - 1));
}

int	main (int argc, char *argv[])
{
	char	*pt;
	int		*pt2;
	int		i;

	i = 0;
	pt2 = &i;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		pt = argv[1];
		i = ft_comprobar_parametro(pt);
	}
	if (i == 31)
		pt2 = generar_tablero(i);
	else
		write(1, "Error\n", 6);
	if (solver(pt2, 1, 1) == 1)
		imprimir_tablero(pt2);
	else
		write(1, "NoSol\n", 6);
	return (0);
}
