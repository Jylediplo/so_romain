/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:18:20 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 11:54:07 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_first_line(t_game *game)
{
	t_axis	coordinates;
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	mlx_ptr = game->window.mlx_ptr;
	win_ptr = game->window.win_ptr;
	coordinates.x = 0;
	coordinates.y = 0;
	i = 0;
	while (i < game->map.rows)
	{
		if (i == 0)
			draw(mlx_ptr, win_ptr, game->images.both_tree, &coordinates);
		else
			draw(mlx_ptr, win_ptr, game->images.bottom_tree, &coordinates);
		coordinates.x += 64;
		i++;
	}
	coordinates.x -= 64;
	draw(mlx_ptr, win_ptr, game->images.both_tree, &coordinates);
}

void	draw_last_line(t_game *game, int y)
{
	t_axis	coordinates;
	int		i;

	coordinates.x = 0;
	coordinates.y = y * 64;
	i = 0;
	while (i < game->map.rows)
	{
		if (i != 0)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.top_tree, &coordinates);
		coordinates.x += 64;
		i++;
	}
	coordinates.x -= 64;
	draw(game->window.mlx_ptr, game->window.win_ptr,
		game->images.both_tree, &coordinates);
}

void	draw_intermediate_1(t_game *game, int y, int i, t_axis *coordinates)
{
	if (game->map.map[y][i] == 'P')
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->player.image, coordinates);
	else if (game->map.map[y][i] == '0')
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->images.floor, coordinates);
	else if (game->map.map[y][i] == 'C')
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->images.coin, coordinates);
	else if (game->map.map[y][i] == 'E')
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->images.exit_close, coordinates);
	else if (game->map.map[y][i] == '1')
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->images.stone, coordinates);
}

void	draw_intermediate(t_game *game, int y)
{
	t_axis	coordinates;
	int		i;

	coordinates.x = 0;
	coordinates.y = y * 64;
	i = -1;
	while (++i < game->map.rows)
	{
		if (i == 0)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.both_tree, &coordinates);
		else
			draw_intermediate_1(game, y, i, &coordinates);
		coordinates.x += 64;
	}
	coordinates.x -= 64;
	draw(game->window.mlx_ptr, game->window.win_ptr,
		game->images.both_tree, &coordinates);
}
