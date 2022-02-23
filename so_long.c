/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:59:16 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/23 10:53:26 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	t_data	grass;
	t_data	wall;
	t_data	key;
	t_data	chest;
	t_data	pirate;

	width = 32;
	height = 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 128, 128, "Hello world!");
	grass.img = mlx_new_image(mlx, 32, 32);
	wall.img = mlx_new_image(mlx, 32, 32);
	key.img = mlx_new_image(mlx, 32, 32);
	chest.img = mlx_new_image(mlx, 32, 32);
	pirate.img = mlx_new_image(mlx, 32, 32);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	// printf("%i\n", img.bits_per_pixel);
	// printf("%i\n", img.size_line);
	// printf("%i\n", img.endian);
	grass.img = mlx_xpm_file_to_image(mlx, "img/grass.xpm", &width, &height);
	wall.img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	key.img = mlx_xpm_file_to_image(mlx, "img/key.xpm", &width, &height);
	chest.img = mlx_xpm_file_to_image(mlx, "img/chest.xpm", &width, &height);
	pirate.img = mlx_xpm_file_to_image(mlx, "img/pirate.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, grass.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, grass.img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, grass.img, 96, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 32, 0);
	mlx_put_image_to_window(mlx, mlx_win, key.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, chest.img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, chest.img, 32, 0);
	mlx_put_image_to_window(mlx, mlx_win, pirate.img, 96, 0);
	mlx_loop(mlx);
}
