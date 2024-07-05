/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:32:55 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 03:04:35 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_and_wall_len_tester(t_data *data)
{
	int				len;
	int				tmp;
	char			*line;
	int				i;

	i = 0;
	len = 0;
	tmp = 1;
	line = get_next_line(data->fd);
	variable_null(line);
	data->map2d = ft_calloc(sizeof(char *), 1000);
	while (line)
	{
		len += line_len(line);
		if (!(len / tmp == line_len(line)))
			return (free_line(line));
		data->map2d[i] = line;
		line = get_next_line(data->fd);
		tmp++;
		i++;
	}
	data->map_size = len;
	data->map_height = tmp - 1;
	data->map_width = len / (tmp - 1);
	return (!free_line(line));
}

int	line_checker(t_data *data)
{
	int	i;
	int	delimeter;

	i = 0;
	delimeter = 0;
	if (!data->map2d)
		return (0);
	while (data->map2d[0][i] && data->map2d[data->map_height -1][i])
	{
		if (data->map2d[0][i] != '1' 
				|| data->map2d[data->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (delimeter < data->map_height)
	{
		if (data->map2d[i][0] != '1' 
					|| data->map2d[i][data->map_width - 1] != '1')
			return (0);
		i++;
		delimeter++;
	}
	return (1);
}

int	game_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map2d[i])
	{
		while (data->map2d[i][j])
		{
			playable(data, data->map2d[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	if (data->player != 1 || data->exit != 1 || data->collect < 1)
		return (0);
	return (1);
}

int	map_checker(t_data *data)
{
	if (!line_checker(data))
		return (0);
	else if (!character_check(data))
		return (0);
	else if (!game_control(data))
		return (0);
	else if (!movement_control(data))
		return (0);
	return (1);
}

int	main(int a, char **args)
{
	t_data	*data;
	int		fd;

	data = ft_calloc(sizeof(t_data), 1);
	if (a == 2)
	{
		fd = open(args[1], O_RDONLY);
		data->fd = fd;
		path_control(args[1]);
		if (data->fd < 0)
			ft_printf("An error occurred while reading the map file\n");
		else if (get_map_and_wall_len_tester(data))
		{
			if (map_checker(data))
				render_map(data);
			else
				ft_printf("Check your map\n");
		}
		else
			ft_printf("Check your map\n");
	}
	else
		ft_printf("Please specify the map correctly\n");
	mlx_loop(data->mlx);
	return (0);
}
