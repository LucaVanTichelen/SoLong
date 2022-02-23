/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:59:16 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/23 11:15:48 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	width = 32;
	height = 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 34 * 32, 6 * 32, "so_long");
	grass.img = mlx_new_image(mlx, 32, 32);
	wall.img = mlx_new_image(mlx, 32, 32);
	key.img = mlx_new_image(mlx, 32, 32);
	chest.img = mlx_new_image(mlx, 32, 32);
	pirate.img = mlx_new_image(mlx, 32, 32);
	grass.img = mlx_xpm_file_to_image(mlx, "img/grass.xpm", &width, &height);
	wall.img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	key.img = mlx_xpm_file_to_image(mlx, "img/key.xpm", &width, &height);
	chest.img = mlx_xpm_file_to_image(mlx, "img/chest.xpm", &width, &height);
	pirate.img = mlx_xpm_file_to_image(mlx, "img/pirate.xpm", &width, &height);

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
	mlx_loop(mlx);
}
