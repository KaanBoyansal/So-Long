/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:55:08 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/11 22:50:15 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
int				nbra(int nbr);
int				pointer(unsigned long int n);
int				putchara(int a);
int				str(char *str);
int				pointerx(unsigned int n);
int				upper_pointerx(unsigned int n);
unsigned int	nbru(unsigned int nbr);

#endif