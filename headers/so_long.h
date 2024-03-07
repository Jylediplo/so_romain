/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:38:50 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 15:31:48 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

typedef struct s_images
{
	void		*floor;
	void		*bottom_tree;
	void		*top_tree;
	void		*both_tree;
	void		*coin;
	void		*exit_close;
	void		*exit_open;
	void		*stone;
	void		*floor1;
}	t_images;

typedef struct s_axis
{
	int	x;
	int	y;

}	t_axis;

typedef struct s_map
{
	int		rows;
	int		lines;
	char	**map;
	int		collectible;
	int		exit;
	int		player;
	char	previous_tile;
	t_axis	exit_pos;

}	t_map;

typedef struct s_player
{
	void		*image;
	void		*player_exit;
	int			collected_items;
	int			moves;
	t_axis		axis;

}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;

}	t_window;

typedef struct s_game
{
	t_images	images;
	t_map		map;
	t_player	player;
	t_window	window;
}				t_game;

void	ft_putnbr(int n);
void	ft_free(char **map);
void	parse_map(char *path_map, t_game *game);
void	check_map(t_game *game);
void	check_map_path(t_game *game);
void	load_map(t_game *game);
void	error_message(char *message, char **map);
void	get_size(t_map *map);
void	check_first_line(t_map size, char **map);
void	check_last(t_map size, char **map);
void	draw(void *mlx_ptr, void *win_ptr, void *image, t_axis *coordinates);
void	load_images(t_game *game);
void	draw_images(t_game *game);
void	draw_first_line(t_game *game);
void	draw_last_line(t_game *game, int y);
void	draw_intermediate(t_game *game, int y);
void	display_moves(t_game *game);
void	check_next_tile(char next_tile, t_game *game);
int		key_hook(int keycode, t_game *game);
void	destroy_all_images(t_game *game);

#endif