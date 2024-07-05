/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:55:00 by mboyansa          #+#    #+#             */
/*   Updated: 2023/03/04 01:32:48 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(int a)
{
	char	b;

	b = a + '0';
	write(1, &b, 1);
	return (1);
}

int	nbra(int nbr)
{
	int	sayac;

	sayac = 0;
	if (nbr >= 0 && nbr <= 9)
		sayac += ft_write(nbr);
	else if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		sayac += write(1, "-", 1);
		sayac += nbra(nbr * (-1));
	}
	else
	{
		sayac += nbra(nbr / 10);
		sayac += nbra(nbr % 10);
	}
	return (sayac);
}
