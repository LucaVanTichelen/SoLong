/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:33:47 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/16 16:14:49 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	char	*path;
// 	int		img_width;
// 	int		img_height;

// 	path = "floor.xpm";
// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
// }

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	key_hook(int keycode, void *param)
{
	printf("key: %d\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	if (button == 1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFC0CB);
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2800, 1500, "mlx 42");
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_expose_hook(mlx.win_ptr, expose_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 								&img.line_length, &img.endian);
// 	for (int i = 5; i <= 555; i++)
// 	{
// 		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
// 		my_mlx_pixel_put(&img, i, 555, 0x00FF0000);
// 	}
// 	for (int i = 5; i <= 555; i++)
// 	{
// 		my_mlx_pixel_put(&img, 5, i, 0x00FF0000);
// 		my_mlx_pixel_put(&img, 555, i, 0x00FF0000);
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
