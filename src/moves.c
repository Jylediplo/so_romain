/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:19:49 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 11:55:20 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_up(t_game *game)
{
	t_axis	coordinates;
	char	next_tile;

	coordinates.x = game->player.axis.x * 64;
	coordinates.y = game->player.axis.y * 64;
	next_tile = game->map.map[game->player.axis.y - 1][game->player.axis.x];
	if (next_tile != '1')
	{
		if (game->map.previous_tile != 'E')
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.floor1, &coordinates);
		if (game->map.previous_tile == 'E'
			&& game->player.collected_items != game->map.collectible)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.exit_close, &coordinates);
		coordinates.y = coordinates.y - 64;
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->player.image, &coordinates);
		game->player.axis.y = game->player.axis.y - 1;
		game->map.previous_tile = '0';
		display_moves(game);
		check_next_tile(next_tile, game);
	}
}

void	move_right(t_game *game)
{
	t_axis	coordinates;
	char	next_tile;

	coordinates.x = game->player.axis.x * 64;
	coordinates.y = game->player.axis.y * 64;
	next_tile = game->map.map[game->player.axis.y][game->player.axis.x + 1];
	if (next_tile != '1')
	{
		if (game->map.previous_tile != 'E')
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.floor1, &coordinates);
		if (game->map.previous_tile == 'E'
			&& game->player.collected_items != game->map.collectible)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.exit_close, &coordinates);
		coordinates.x = coordinates.x + 64;
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->player.image, &coordinates);
		game->player.axis.x = game->player.axis.x + 1;
		game->map.previous_tile = '0';
		display_moves(game);
		check_next_tile(next_tile, game);
	}
}

void	move_left(t_game *game)
{
	t_axis	coordinates;
	char	next_tile;

	coordinates.x = game->player.axis.x * 64;
	coordinates.y = game->player.axis.y * 64;
	next_tile = game->map.map[game->player.axis.y][game->player.axis.x - 1];
	if (next_tile != '1')
	{
		if (game->map.previous_tile != 'E')
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.floor1, &coordinates);
		if (game->map.previous_tile == 'E'
			&& game->player.collected_items != game->map.collectible)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.exit_close, &coordinates);
		coordinates.x = coordinates.x - 64;
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->player.image, &coordinates);
		game->player.axis.x = game->player.axis.x - 1;
		game->map.previous_tile = '0';
		display_moves(game);
		check_next_tile(next_tile, game);
	}
}

void	move_bottom(t_game *game)
{
	t_axis	coordinates;
	char	next_tile;

	coordinates.x = game->player.axis.x * 64;
	coordinates.y = game->player.axis.y * 64;
	next_tile = game->map.map[game->player.axis.y + 1][game->player.axis.x];
	if (next_tile != '1')
	{
		if (game->map.previous_tile != 'E')
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.floor1, &coordinates);
		if (game->map.previous_tile == 'E'
			&& game->player.collected_items != game->map.collectible)
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->images.exit_close, &coordinates);
		coordinates.y = coordinates.y + 64;
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->player.image, &coordinates);
		game->player.axis.y = game->player.axis.y + 1;
		game->map.previous_tile = '0';
		display_moves(game);
		check_next_tile(next_tile, game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 'w')
		move_up(game);
	if (keycode == 'd')
		move_right(game);
	if (keycode == 'a')
		move_left(game);
	if (keycode == 's')
		move_bottom(game);
	if (keycode == 65307)
	{
		destroy_all_images(game);
		mlx_loop_end(game->window.mlx_ptr);
	}
	return (0);
}
