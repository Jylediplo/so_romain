/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:45:56 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 11:53:16 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	destroy_all_images(t_game *game)
{
	mlx_destroy_image(game->window.mlx_ptr, game->images.both_tree);
	mlx_destroy_image(game->window.mlx_ptr, game->images.bottom_tree);
	mlx_destroy_image(game->window.mlx_ptr, game->images.coin);
	mlx_destroy_image(game->window.mlx_ptr, game->images.exit_close);
	mlx_destroy_image(game->window.mlx_ptr, game->images.exit_open);
	mlx_destroy_image(game->window.mlx_ptr, game->images.floor1);
	mlx_destroy_image(game->window.mlx_ptr, game->images.floor);
	mlx_destroy_image(game->window.mlx_ptr, game->images.stone);
	mlx_destroy_image(game->window.mlx_ptr, game->images.top_tree);
	mlx_destroy_image(game->window.mlx_ptr, game->player.image);
	mlx_destroy_image(game->window.mlx_ptr, game->player.player_exit);
}

void	mlx_destroyer(t_game *game)
{
	mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->window.mlx_ptr);
	free(game->window.mlx_ptr);
}

int	close_window(t_game *game)
{
	destroy_all_images(game);
	mlx_loop_end(game->window.mlx_ptr);
	return (0);
}

void	check_next_tile(char next_tile, t_game *game)
{
	if (next_tile == 'C')
	{
		game->player.collected_items++;
		game->map.map[game->player.axis.y][game->player.axis.x] = '0';
	}
	if (game->player.collected_items == game->map.collectible)
		draw(game->window.mlx_ptr, game->window.win_ptr,
			game->images.exit_open, &game->map.exit_pos);
	if (next_tile == 'E')
	{
		if (game->player.collected_items == game->map.collectible)
		{
			mlx_loop_end(game->window.mlx_ptr);
			destroy_all_images(game);
			write(1, "You just won !!!\n", 17);
		}
		else
			draw(game->window.mlx_ptr, game->window.win_ptr,
				game->player.player_exit, &game->map.exit_pos);
		game->map.previous_tile = 'E';
	}
}

void	load_map(t_game *game)
{
	game->window.mlx_ptr = mlx_init();
	game->window.win_ptr = mlx_new_window(game->window.mlx_ptr,
			game->window.win_width, game->window.win_height, "So loong");
	load_images(game);
	draw_images(game);
	mlx_hook(game->window.win_ptr, 17, 1L << 0, close_window, game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, key_hook, game);
	mlx_loop(game->window.mlx_ptr);
	mlx_destroyer(game);
}
