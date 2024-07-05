/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:24:29 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 03:07:03 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	p = str;
	while (*s)
	{
		*p = *s;
		p++;
		s++;
	}
	*p = '\0';
	return (str);
}

void	images(t_data *data)
{
	data->img[0] = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img_x, &data->img_y);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->img_x, &data->img_y);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, PL_FT,
			&data->img_x, &data->img_y);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->img_x, &data->img_y);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&data->img_x, &data->img_y);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, PL_BACK,
			&data->img_x, &data->img_y);
}
