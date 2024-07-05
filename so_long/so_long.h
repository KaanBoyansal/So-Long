/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:29:27 by mboyansa          #+#    #+#             */
/*   Updated: 2023/07/16 04:03:29 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"
# define PL_FT "./img/player_front.xpm"
# define PL_BACK "./img/player_back.xpm"
# define GROUND "./img/grass.xpm"
# define WALL "./img/brick.xpm"
# define EXIT "./img/exit_door_position_1.xpm"
# define COLLECT "./img/game_sake.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	**img;
	int		player_x;
	int		player_y;
	int		player_step;
	int		img_x;
	int		img_y;
	int		collect;
	int		exit;
	int		player;
	int		map_size;
	int		fd;
	int		map_width;
	int		map_height;
	char	**map2d;
	char	**dot_map;
}	t_data;

void	images(t_data *data);
void	render_check(t_data *data, char c, int ren_x, int ren_y);
void	game_renderer(t_data *data);
void	game_renderer2(t_data *data);
void	render_check2(t_data *data, char c, int ren_x, int ren_y);
void	move_up(t_data *data);
void	moveleft(t_data *data);
void	movedown(t_data *data);
void	close_game(t_data *data);
void	moveright(t_data *data);
int		key_events(int key_code, t_data *data);
void	render_map(t_data *data);
int		free_line(char	*str);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, unsigned int n);
int		line_len(char *str);
void	playable(t_data	*data, char a);
int		character_check(t_data *data);
void	variable_null(char *line);
void	path_control(char *path);
void	map_test(t_data *data, int x, int y);
int		movement_control(t_data *data);
int		dot_cal(t_data *data);
char	*ft_strdup(const char *s);
void	dot_map(t_data *data);

#endif