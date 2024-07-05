/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:55:04 by mboyansa          #+#    #+#             */
/*   Updated: 2023/03/03 23:08:12 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer(unsigned long int n)
{
	int	sayac;

	sayac = 0;
	if (n <= 15)
	{
		sayac += write(1, &"0123456789abcdef"[n], 1);
		return (sayac);
	}
	else
	{
		sayac += pointer(n / 16);
		sayac += pointer(n % 16);
	}
	return (sayac);
}

int	pointerx(unsigned int n)
{
	int	sayac;

	sayac = 0;
	if (n <= 15)
	{
		sayac += write(1, &"0123456789abcdef"[n], 1);
		return (sayac);
	}
	else
	{
		sayac += pointerx(n / 16);
		sayac += pointerx(n % 16);
	}
	return (sayac);
}

int	upper_pointerx(unsigned int n)
{
	int	sayac;

	sayac = 0;
	if (n <= 15)
	{
		sayac += write(1, &"0123456789ABCDEF"[n], 1);
		return (sayac);
	}
	else
	{
		sayac += upper_pointerx(n / 16);
		sayac += upper_pointerx(n % 16);
	}
	return (sayac);
}
