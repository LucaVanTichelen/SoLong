/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:59:16 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/23 14:43:36 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode)
{
	printf("%i\n", keycode);
	return (0);
}

int	clean_exit()
{
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		fd;
	int		i;
	int		j;
	char	*str;
	t_data	grass;
	t_data	wall;
	t_data	key;
	t_data	chest;
	t_data	pirate;

	fd = open("maps/map2.ber", O_RDONLY);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 34 * 32, 6 * 32, "so_long");
	grass.img = mlx_xpm_file_to_image(mlx, "img/grass.xpm", &width, &height);
	wall.img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	key.img = mlx_xpm_file_to_image(mlx, "img/key.xpm", &width, &height);
	chest.img = mlx_xpm_file_to_image(mlx, "img/chest.xpm", &width, &height);
	pirate.img = mlx_xpm_file_to_image(mlx, "img/pirate.xpm", &width, &height);
	printf("%i - %i\n", width, height);
	i = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == '1')
			{
				mlx_put_image_to_window(mlx, mlx_win, wall.img, j * 32, i * 32);
			}
			else
			{
				mlx_put_image_to_window(mlx, mlx_win, grass.img, j * 32, i * 32);
				if (str[j] == 'C')
				{
					mlx_put_image_to_window(mlx, mlx_win, key.img, j * 32, i * 32);
				}
				if (str[j] == 'P')
				{
					mlx_put_image_to_window(mlx, mlx_win, pirate.img, j * 32, i * 32);
				}
				if (str[j] == 'E')
				{
					mlx_put_image_to_window(mlx, mlx_win, chest.img, j * 32, i * 32);
				}
			}
			j++;
		}
		i++;
	}
	mlx_key_hook(mlx_win, key_hook, 0);
	mlx_hook(mlx_win, 17, 0, clean_exit, 0);
	mlx_loop(mlx);
}
