/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 06:05:37 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 04:41:53 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_test(t_data *data, int x, int y)
{
	if (data->dot_map[y][x + 1] == '0' || data->dot_map[y][x + 1] == 'C'
		|| data->dot_map[y][x + 1] == 'P' || data->dot_map[y][x + 1] == 'E')
	{
		data->dot_map[y][x + 1] = '.';
		map_test(data, x + 1, y);
	}
	if (data->dot_map[y][x - 1] == '0' || data->dot_map[y][x - 1] == 'C'
		|| data->dot_map[y][x - 1] == 'P' || data->dot_map[y][x - 1] == 'E')
	{
		data->dot_map[y][x - 1] = '.';
		map_test(data, x - 1, y);
	}
	if (data->dot_map[y + 1][x] == '0' || data->dot_map[y + 1][x] == 'C'
		|| data->dot_map[y + 1][x] == 'P' || data->dot_map[y + 1][x] == 'E')
	{
		data->dot_map[y + 1][x] = '.';
		map_test(data, x, y + 1);
	}
	if (data->dot_map[y - 1][x] == '0' || data->dot_map[y - 1][x] == 'C'
		|| data->dot_map[y - 1][x] == 'P' || data->dot_map[y - 1][x] == 'E')
	{
		data->dot_map[y - 1][x] = '.';
		map_test(data, x, y - 1);
	}
}

int	dot_cal(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dot_map[i])
	{
		j = 0;
		while (data->dot_map[i][j])
		{
			if (data->dot_map[i][j] == 'E' || data->dot_map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	dot_map(t_data *data)
{
	int	i;

	i = 0;
	data->dot_map = ft_calloc(sizeof(char *), 1000);
	while (data->map2d[i])
	{
		data->dot_map[i] = ft_strdup(data->map2d[i]);
		i++;
	}
}

int	character_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map2d[i])
	{
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] != '1' && data->map2d[i][j] != 'C' 
					&& data->map2d[i][j] != 'P' 
							&& data->map2d[i][j] != 'E' 
								&& data->map2d[i][j] != '0' 
									&& data->map2d[i][j] != '\n')
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	render_check(t_data *data, char c, int ren_x, int ren_y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[0], ren_x, ren_y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[1], ren_x, ren_y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[3], ren_x, ren_y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[0], ren_x, ren_y);
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[4], ren_x, ren_y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[0], ren_x, ren_y);
		mlx_put_image_to_window(data->mlx, data->win, 
			data->img[2], ren_x, ren_y);
	}
}
