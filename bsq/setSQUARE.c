/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setSQUARE.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:00:59 by jvico-ga          #+#    #+#             */
/*   Updated: 2021/07/14 23:17:38 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void			setSQUARE(char *buf);
unsigned int	rowWeight(char *buf);

unsigned int	firstSpaceJump(char *buf);
unsigned int	columMatch(char *buf);
unsigned int	get_pos_tab(unsigned int row, unsigned int colum,
					char *buf, unsigned int rowWeight);

void	initialization(unsigned int *x, unsigned int *y, unsigned int row,
	unsigned int column)
{
	*x = row;
	*y = column;
}

unsigned int	searchPossibleSquare(unsigned int row, unsigned int	column,
	char *buf)
{
	unsigned int	position;
	unsigned int	x;
	unsigned int	y;
	unsigned int	limit;

	limit = 0;
	initialization(&x, &y, row, column);
	while (y + limit <= columMatch(buf) && x + limit <= rowWeight(buf))
	{
		while (row <= x + limit)
		{
			while (column <= y + limit)
			{
				position = get_pos_tab(row, column, buf, rowWeight(buf));
				if (buf[position] != buf[firstSpaceJump(buf) - 3])
					return (limit);
				column++;
			}
			column = y;
			row++;
		}
		row = x;
		limit++;
	}
	return (limit);
}

void	drawSquare (char *buf, unsigned int *pos, unsigned int count)
{
	unsigned int	position;
	unsigned int	x;
	unsigned int	y;

	x = pos[1];
	y = pos[0];
	while (x < pos[1] + count)
	{
		while (y < pos[0] + count)
		{
			position = get_pos_tab(x, y, buf, rowWeight(buf));
			buf[position] = buf[firstSpaceJump(buf) - 1];
			y++;
		}
		y = pos[0];
		x++;
	}
}

void	setSQUARE(char *buf)
{
	unsigned int	column;
	unsigned int	row;
	unsigned int	count;
	unsigned int	pos[2];

	count = 0;
	column = 0;
	row = 0;
	while (column < columMatch(buf))
	{
		while (row < rowWeight(buf))
		{
			if (searchPossibleSquare(row, column, buf) > count)
			{
				count = searchPossibleSquare(row, column, buf);
				pos[0] = column;
				pos[1] = row;
			}
			row++;
		}
		row = 0;
		column++;
	}
	drawSquare(buf, pos, count);
}
