/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:00:16 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:32:53 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *game, int i, int j)
{
	if (game->map[j][i] != '1')
	{
		printf("Moves : %i\n", ++game->moves);
		if (game->map[j][i] == 'E' && game->keys == 0)
			clean_exit(game);
		if (game->map[j][i] == 'C')
		{
			game->map[j][i] = 0;
			game->keys -= 1;
		}
		if (game->map[game->pos.y][game->pos.x] != 'E')
			mlx_put_image_to_window(game->mlx, game->win, \
			game->grass.img, game->pos.x * 32, game->pos.y * 32);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->grass.img, game->pos.x * 32, game->pos.y * 32);
			mlx_put_image_to_window(game->mlx, game->win, \
			game->chest.img, game->pos.x * 32, game->pos.y * 32);
		}
		mlx_put_image_to_window(game->mlx, game->win, \
			game->pirate.img, i * 32, j * 32);
		game->pos.x = i;
		game->pos.y = j;
	}
}
