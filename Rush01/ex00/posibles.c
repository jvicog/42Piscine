/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posibles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:05:35 by dexposit          #+#    #+#             */
/*   Updated: 2021/07/04 20:56:07 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ind_pista_arriba(int i)
{
	return (i * 2);
}

int	ind_pista_abajo(int i)
{
	return (ind_pista_arriba(i) + 8);
}

int	ind_pista_izq(int i)
{
	return (16 + (i * 2));
}

int	ind_pista_der(int i)
{
	return (ind_pista_izq(i) + 8);
}
