/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:05:42 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 04:41:27 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 64 * data->map_height;
	x = 64 * data->map_width;
	data->img = (void **)malloc(sizeof(void *) * 6);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, x, y, "so_long");
	data->img_x = 64;
	data->img_y = 64;
	data->player_step = 0;
	images(data);
	game_renderer(data);
	mlx_hook(data->win, 3, 1L << 0, key_events, data);
}

void	game_renderer(t_data *data)
{
	int	i;
	int	j;
	int	ren_x;
	int	ren_y;

	i = 0;
	ren_y = 0;
	while (data->map2d[i])
	{
		j = 0;
		ren_x = 0;
		while (data->map2d[i][j])
		{
			render_check(data, data->map2d[i][j], ren_x, ren_y);
			ren_x += 64;
			j++;
		}
		ren_y += 64;
		i++;
	}
}

void	variable_null(char *line)
{
	if (!line)
	{
		ft_printf("Map is empty\n");
		exit(0);
	}
}

void	path_control(char *path)
{
	int	end;

	if (ft_strlen(path) < 4)
	{
		ft_printf("Check your file\n");
		exit(0);
	}
	end = ft_strlen(path) - 1;
	if (path[end] != 'r' && path[end - 1] != 'e' 
		&& path[end - 2] != 'b' && path[end - 3] != '.')
	{
		ft_printf("Check your file\n");
		exit(0);
	}
}

int	movement_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	dot_map(data);
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				map_test(data, j, i);
				break ;
			}
			j++;
		}
		i++;
	}
	if (!dot_cal(data))
		return (0);
	return (1);
}
