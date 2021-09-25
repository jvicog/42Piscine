/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 13:51:23 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/04 21:13:33 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int	get_pos_tab(int x, int y);

int	isSafe(int *tablero, int row, int col, int num)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (y <= N)
	{
		if (tablero[get_pos_tab(col, y)] == num)
			return (0);
		y++;
	}
	while (x <= N)
	{
		if (tablero[get_pos_tab(x, row)] == num)
			return (0);
		x++;
	}
	return (1);
}

int	solver (int *tablero, int row, int col)
{
	int	num;

	num = 1;
	if (row == N && col == N + 1)
		return (1);
	if (col > N)
	{
		row++;
		col = 1;
	}
	if (tablero[get_pos_tab(col, row)] > 0)
		return (solver(tablero, row, col + 1));
	while (num <= N)
	{
		if (isSafe(tablero, row, col, num) == 1)
		{
			tablero[get_pos_tab(col, row)] = num;
			if (solver(tablero, row, col + 1) == 1)
				return (1);
		}
		tablero[get_pos_tab(col, row)] = 0;
		num++;
	}
	return (0);
}
