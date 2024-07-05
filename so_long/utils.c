/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:04:59 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/13 03:44:32 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playable(t_data	*data, char a)
{
	if (a == 'C')
		data->collect++;
	else if (a == 'P')
		data->player++;
	else if (a == 'E')
		data->exit++;
}

int	free_line(char	*str)
{
	free(str);
	return (0);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	p = malloc(nelem * elsize);
	if (!p)
		return (0);
	ft_bzero(p, nelem * elsize);
	return (p);
}

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	char			*c;

	i = 0;
	c = s;
	while (i < n)
		c[i++] = 0;
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}
