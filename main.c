/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:33:47 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/16 15:12:51 by lvan-tic         ###   ########.fr       */
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
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
