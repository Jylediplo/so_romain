/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:32:33 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 12:09:38 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	initialise_map(t_game *game)
{
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.lines = 0;
	game->map.rows = 0;
	game->map.map = NULL;
	game->map.player = 0;
	game->player.moves = 0;
	game->player.collected_items = 0;
	game->map.previous_tile = '0';
}

void	initialise_window(t_game *game)
{
	game->window.img_width = 64;
	game->window.img_height = 64;
	game->window.win_width = game->map.rows * 64;
	game->window.win_height = game->map.lines * 64;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "So long must contains one argument !\n", 37);
		return (1);
	}
	initialise_map(&game);
	parse_map(argv[1], &game);
	check_map(&game);
	check_map_path(&game);
	initialise_window(&game);
	load_map(&game);
	ft_free(game.map.map);
	return (0);
}
