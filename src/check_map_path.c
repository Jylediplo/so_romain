/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:27:44 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 15:46:41 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_dup(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.lines)
		free(map[i++]);
	free(map);
}

char	**dup_map(t_game game)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	new_map = malloc(sizeof(char *) * (game.map.lines + 1));
	if (!new_map)
		return (NULL);
	while (i < game.map.lines)
	{
		new_map[i] = malloc(sizeof(char) * game.map.rows + 1);
		if (!new_map[i])
			return (ft_free(new_map), NULL);
		j = 0;
		while (j < game.map.rows)
		{
			new_map[i][j] = game.map.map[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = "\0";
	return (new_map);
}

void	path_finder(char **map, int x, int y)
{
	map[x][y] = '*';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C' || map[x + 1][y] == 'E')
		path_finder(map, x + 1, y);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x - 1][y] == 'E')
		path_finder(map, x - 1, y);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C' || map[x][y + 1] == 'E')
		path_finder(map, x, y + 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x][y - 1] == 'E')
		path_finder(map, x, y - 1);
}

void	coins_or_exit_left(char **map, t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.map.lines)
	{
		j = 0;
		while (j < game.map.rows)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_free(game.map.map);
				free_dup(map, &game);
				write(2, "Cannot reach coins or exit !\n", 29);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_map_path(t_game *game)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = dup_map(*game);
	if (!new_map)
	{
		ft_free(game->map.map);
		exit(1);
	}
	x = game->player.axis.y;
	y = game->player.axis.x;
	path_finder(new_map, x, y);
	coins_or_exit_left(new_map, *game);
	free_dup(new_map, game);
}
