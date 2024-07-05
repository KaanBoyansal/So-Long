/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:41:13 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 04:34:51 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movedown(t_data *data)
{
	if (data->map2d[data->player_y + 1][data->player_x] != '1')
	{
		if (data->map2d[data->player_y + 1][data->player_x] == 'E')
		{
			if (data->collect != 0)
				return ;
			else
			{
				data->player_step++;
				ft_printf("Steps : %d\n", data->player_step);
				close_game(data);
			}
		}
		if (data->map2d[data->player_y + 1][data->player_x] == 'C')
			data->collect--;
		data->map2d[data->player_y][data->player_x] = '0';
		data->player_y++;
		data->map2d[data->player_y][data->player_x] = 'P';
		data->player_step++;
		ft_printf("Steps : %d\n", data->player_step);
		mlx_clear_window(data->mlx, data->win);
		game_renderer(data);
	}
}

void	moveright(t_data *data)
{
	if (data->map2d[data->player_y][data->player_x + 1] != '1')
	{
		if (data->map2d[data->player_y][data->player_x + 1] == 'E')
		{
			if (data->collect != 0)
				return ;
			else
			{
				data->player_step++;
				ft_printf("Steps : %d\n", data->player_step);
				close_game(data);
			}
		}
		if (data->map2d[data->player_y][data->player_x - 1] == 'C')
			data->collect--;
		data->map2d[data->player_y][data->player_x] = '0';
		data->player_x++;
		data->map2d[data->player_y][data->player_x] = 'P';
		data->player_step++;
		ft_printf("Steps : %d\n", data->player_step);
		mlx_clear_window(data->mlx, data->win);
		game_renderer(data);
	}
}

void	close_game(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
