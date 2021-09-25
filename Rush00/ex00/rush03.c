/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaballe <acaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:08:41 by pauladelpin       #+#    #+#             */
/*   Updated: 2021/06/27 18:07:32 by acaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//declare prototype
void	ft_putchar(char c);

//function to define lines. each loop is a type of line
void	rectangle (int x, int y, int auxX, int auxY)
{
	if (y == auxY || y == 1)
	{
		if (x == auxX)
			ft_putchar('A');
		else if (x == 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (x == auxX || x == 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

//function to check sign of x,y. obtain variable neg
int	check (int *ptx, int *pty, int neg)
{
	if (*ptx < 0)
	{
		*ptx *= -1;
		neg *= -1;
	}
	if (*pty < 0)
	{
		*pty *= -1;
		neg *= -1;
	}
	return (neg);
}

//funtion to define the ending of each line
void	jump (int *ptx, int *pty, int auxX)
{
	if (*pty != 1)
		ft_putchar('\n');
	*ptx = auxX;
	*pty = *pty - 1;
}

//function to print line based on x,y values
void	rush (int x, int y)
{
	int		auxX;
	int		auxY;
	int		neg;
	int		*ptx;
	int		*pty;

	ptx = &x;
	pty = &y;
	neg = check(ptx, pty, 1);
	auxX = x;
	auxY = y;
	while (y != 0)
	{
		while (x != 0)
		{
			if (neg == 1)
				rectangle (x, y, auxX, auxY);
			else
				rectangle (x, auxY - y + 1, auxX, auxY);
			x--;
		}
		jump (ptx, pty, auxX);
	}
}
