/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_and_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:15:20 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/28 11:50:04 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_putnbr(int n)
{
	char	character;

	if (n < 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			n *= -1;
			write(1, "-", 1);
		}
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		character = n % 10 + '0';
		write(1, &character, 1);
	}
	if (n <= 9 && n >= 0)
	{
		character = n % 10 + '0';
		write(1, &character, 1);
	}
}

void	load_images_2(t_game *game)
{
	void	*mlx_ptr;
	int		img_width;
	int		img_height;

	img_width = game->window.img_width;
	img_height = game->window.img_height;
	mlx_ptr = game->window.mlx_ptr;
	game->images.coin = mlx_xpm_file_to_image(mlx_ptr,
			"./images/gold_nugget.xpm", &img_width, &img_height);
	game->images.exit_close = mlx_xpm_file_to_image(mlx_ptr,
			"./images/exit_close.xpm", &img_width, &img_height);
	game->images.exit_open = mlx_xpm_file_to_image(mlx_ptr,
			"./images/exit_open.xpm", &img_width, &img_height);
	game->images.stone = mlx_xpm_file_to_image(mlx_ptr,
			"./images/stone.xpm", &img_width, &img_height);
	game->images.floor1 = mlx_xpm_file_to_image(mlx_ptr,
			"./images/floor1.xpm", &img_width, &img_height);
	game->player.player_exit = mlx_xpm_file_to_image(mlx_ptr,
			"./images/tondeuse_exit.xpm", &img_width, &img_height);
}

void	load_images(t_game *game)
{
	void	*mlx_ptr;
	int		img_width;
	int		img_height;

	img_width = game->window.img_width;
	img_height = game->window.img_height;
	mlx_ptr = game->window.mlx_ptr;
	game->images.both_tree = mlx_xpm_file_to_image(mlx_ptr,
			"./images/both_tree64.xpm",
			&img_width, &img_height);
	game->images.top_tree = mlx_xpm_file_to_image(mlx_ptr,
			"./images/top_tree64.xpm",
			&img_width, &img_height);
	game->images.bottom_tree = mlx_xpm_file_to_image(mlx_ptr,
			"./images/bottom_tree64.xpm", &img_width, &img_height);
	game->images.floor = mlx_xpm_file_to_image(mlx_ptr,
			"./images/floor64.xpm",
			&img_width, &img_height);
	game->player.image = mlx_xpm_file_to_image(mlx_ptr,
			"./images/tondeuse.xpm", &img_width, &img_height);
	load_images_2(game);
}

void	draw(void *mlx_ptr, void *win_ptr, void *image, t_axis *coordinates)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, coordinates->x,
		coordinates->y);
}

void	draw_images(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if (y == 0)
			draw_first_line(game);
		else
			draw_intermediate(game, y);
		y++;
	}
	draw_last_line(game, y - 1);
}
