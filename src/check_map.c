/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:20:16 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 11:51:57 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	display_moves(t_game *game)
{
	write(1, "Moves : ", 8);
	game->player.moves += 1;
	ft_putnbr(game->player.moves);
	write(1, "\n", 1);
}

void	check_for_item(char tile, t_game *game, int i, int j)
{
	if (tile == 'P')
	{
		game->map.player++;
		game->player.axis.x = j;
		game->player.axis.y = i;
	}
	if (tile == 'C')
		game->map.collectible++;
	if (tile == 'E')
	{
		game->map.exit_pos.x = j * 64;
		game->map.exit_pos.y = i * 64;
		game->map.exit++;
	}
}

void	manage_map_input(t_game *game, int i, int j)
{
	char	**map;
	char	tile;
	int		rows;

	map = game->map.map;
	rows = game->map.rows;
	tile = game->map.map[i][j];
	if ((j == 0 && tile != '1') || (j == rows - 1 && tile != '1'))
	{
		error_message("Map must be closed !\n", map);
	}
	else if (tile != 'P' && tile != '1' && tile != '0'
		&& tile != 'E' && tile != 'C')
	{
		error_message("Unknown input on map !", map);
	}
	check_for_item(tile, game, i, j);
}

void	check_intermediate(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < game->map.lines -1)
	{
		j = 0;
		while (game->map.map[i][j])
			j++;
		if (j - 1 != game->map.rows)
		{
			error_message("lines must be the same length\n", game->map.map);
		}
		j = 0;
		while (j < game->map.rows)
		{
			manage_map_input(game, i, j);
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	get_size(&game->map);
	check_first_line(game->map, game->map.map);
	check_intermediate(game);
	if (game->map.player > 1 || game->map.player == 0)
		error_message("Map : incorrect starting point\n", game->map.map);
	if (game->map.collectible < 1)
		error_message("Map must contains at least one coin !\n", game->map.map);
	if (game->map.exit > 1 || game->map.exit == 0)
		error_message("Map : incorrect exit !\n", game->map.map);
	check_last(game->map, game->map.map);
}
