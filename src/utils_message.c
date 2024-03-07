/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:14:23 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 12:07:01 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_message(char *message, char **map)
{
	int	length;

	length = ft_strlen(message);
	write(2, "Error\n", 6);
	write(2, message, length);
	ft_free(map);
	exit(1);
}

void	get_size(t_map *map)
{
	int	i;

	i = 0;
	map->rows = ft_strlen(map->map[0]) - 1;
	while (map->map[i])
		i++;
	map->lines = i;
}

void	check_line_length(t_map size, char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	if (i - 1 != size.rows)
		error_message("Each line of the map must be the same length !\n", map);
}

void	check_first_line(t_map size, char **map)
{
	int	i;

	i = 0;
	while (i < size.rows)
	{
		if (map[0][i] != '1')
			error_message("First line must contains only walls\n", map);
		i++;
	}
}

void	check_last(t_map size, char **map)
{
	int	i;

	i = 0;
	while (map[size.lines - 1][i])
		i++;
	if (i != size.rows)
		error_message("last line is not the same length\n", map);
	i = 0;
	while (i < size.rows)
	{
		if (map[size.lines - 1][i] != '1')
			error_message("last line must contains only walls\n", map);
		i++;
	}
}
