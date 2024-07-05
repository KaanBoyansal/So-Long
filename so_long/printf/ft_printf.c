/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:54:54 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/11 23:30:08 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	letter(char per)
{
	if (per != 'c' && per != 'x' && per != 's' && per != 'd'
		&& per != 'p' && per != 'i' && per != 'X' && per != 'u')
		return (1);
	return (0);
}

int	tuce(char per, va_list args)
{
	int	sayac;

	sayac = 0;
	if (per == 'd' || per == 'i')
		sayac += nbra(va_arg(args, int));
	else if (per == 'u')
		sayac += nbru(va_arg(args, unsigned int));
	return (sayac);
}

int	kheck(char per, va_list args)
{
	int	sayac;

	sayac = 0;
	if (per == 'd' || per == 'u' || per == 'i')
		sayac += tuce(per, args);
	else if (per == 'c')
		sayac += putchara(va_arg(args, int));
	else if (per == 's')
		sayac += str(va_arg(args, char *));
	else if (per == 'p')
	{
		write(1, "0x", 2);
		sayac += pointer(va_arg(args, unsigned long int)) + 2;
	}
	else if (per == 'x')
		sayac += pointerx(va_arg(args, unsigned int));
	else if (per == 'X')
		sayac += upper_pointerx(va_arg(args, unsigned int));
	return (sayac);
}

int	ft_check(va_list args, int i, int tmp, const char *str)
{
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			tmp++;
		}
		else if (str[i] == '%' && str[i + 1] == '%' && str[i])
		{
			write(1, "%", 1);
			i++;
			tmp++;
		}
		else if (str[i] == '%' && !letter(str[i + 1]))
		{
			tmp += kheck(str[i + 1], args);
			i += 1;
		}
		i++;
	}
	return (tmp);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	va_start(args, str);
	if (str[i] == '%' && letter(str[i + 1]) && str[i] && str[i + 1] != '%')
	{
		write(1, &str[i + 1], 1);
		tmp++;
		i += 2;
	}
	tmp += ft_check(args, i, tmp, str);
	va_end(args);
	return (tmp);
}
