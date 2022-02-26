/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:39:41 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 11:24:58 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->wall.img, j * 32, i * 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
			game->grass.img, j * 32, i * 32);
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->pirate.img, j * 32, i * 32);
		game->pos.x = j;
		game->pos.y = i;
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->key.img, j * 32, i * 32);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chest.img, j * 32, i * 32);
}

void	img_to_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}

void	create_images(t_game *game)
{
	game->grass.img = mlx_xpm_file_to_image(game->mlx, "img/grass.xpm", \
		&game->grass.width, &game->grass.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", \
		&game->wall.width, &game->wall.height);
	game->key.img = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", \
		&game->key.width, &game->key.height);
	game->chest.img = mlx_xpm_file_to_image(game->mlx, "img/chest.xpm", \
		&game->chest.width, &game->chest.height);
	game->pirate.img = mlx_xpm_file_to_image(game->mlx, "img/pirate.xpm", \
		&game->pirate.width, &game->pirate.height);
	img_to_map(game);
}
