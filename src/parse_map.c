/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:35:22 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 12:06:13 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_free(char **map)
{
	int	count;

	count = 0;
	while (map[count])
	{
		free(map[count]);
		count++;
	}
	free(map);
}

int	nb_of_lines(char *path_map)
{
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = 0;
	line = "start";
	fd = open(path_map, O_RDONLY, 0777);
	if (fd == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 1 && line[0] == '\n')
			break ;
		free(line);
		nb_line++;
	}
	free(line);
	close(fd);
	return (nb_line);
}

char	*fill_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

void	parse_map_1(char *path_map, t_game *game, int nb_line)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path_map, O_RDONLY, 0777);
	if (fd == -1)
	{
		free(game->map.map);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		exit(1);
	}
	while (i < nb_line)
	{
		game->map.map[i] = fill_line(fd);
		if (!game->map.map[i])
		{
			write(2, "malloc error : creating map !\n", 30);
			ft_free(game->map.map);
			exit(1);
		}
		i++;
	}
	game->map.map[i] = 0;
	close(fd);
}

void	parse_map(char *path_map, t_game *game)
{
	int	nb_line;

	nb_line = nb_of_lines(path_map);
	if (nb_line <= 2)
	{
		write(2, "Error\n", 6);
		write(2, "The map must be at least 3 lines long\n", 38);
		exit(1);
	}
	game->map.map = malloc(sizeof(char *) * (nb_line + 1));
	if (!game->map.map)
	{
		write(2, "malloc error : creating map !\n", 30);
		exit(1);
	}
	parse_map_1(path_map, game, nb_line);
}
