/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:51:58 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 04:28:54 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_events(int key_code, t_data *data)
{
	if (key_code == 13)
		move_up(data);
	if (key_code == 0)
		moveleft(data);
	if (key_code == 1)
		movedown(data);
	if (key_code == 2)
		moveright(data);
	if (key_code == 53)
		close_game(data);
	return (0);
}

void	moveleft(t_data *data)
{
	if (data->map2d[data->player_y][data->player_x - 1] != '1')
	{
		if (data->map2d[data->player_y][data->player_x - 1] == 'E')
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
		data->player_x--;
		data->map2d[data->player_y][data->player_x] = 'P';
		data->player_step++;
		ft_printf("Steps : %d\n", data->player_step);
		mlx_clear_window(data->mlx, data->win);
		game_renderer(data);
	}
}

void	move_up(t_data *data)
{
	if (data->map2d[data->player_y - 1][data->player_x] != '1')
	{
		if (data->map2d[data->player_y - 1][data->player_x] == 'E')
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
		if (data->map2d[data->player_y - 1][data->player_x] == 'C')
			data->collect--;
		data->map2d[data->player_y][data->player_x] = '0';
		data->player_y--;
		data->map2d[data->player_y][data->player_x] = 'P';
		data->player_step++;
		ft_printf("Steps : %d\n", data->player_step);
		mlx_clear_window(data->mlx, data->win);
		game_renderer2(data);
	}
}

void	game_renderer2(t_data *data)
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
			render_check2(data, data->map2d[i][j], ren_x, ren_y);
			ren_x += 64;
			j++;
		}
		ren_y += 64;
		i++;
	}
}

void	render_check2(t_data *data, char c, int ren_x, int ren_y)
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
			data->img[5], ren_x, ren_y);
	}
}
