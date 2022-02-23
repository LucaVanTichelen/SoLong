/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:59:16 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/23 10:20:33 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
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
	grass.img = mlx_xpm_file_to_image(mlx, "grass.xpm", &width, &height);
	wall.img = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
	key.img = mlx_xpm_file_to_image(mlx, "key.xpm", &width, &height);
	chest.img = mlx_xpm_file_to_image(mlx, "chest.xpm", &width, &height);
	pirate.img = mlx_xpm_file_to_image(mlx, "pirate.xpm", &width, &height);
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
