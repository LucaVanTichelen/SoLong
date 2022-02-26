/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:59:25 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:54:39 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		clean_exit(game);
	if (keycode == 13)
		move_to(game, game->pos.x, game->pos.y - 1);
	if (keycode == 0)
		move_to(game, game->pos.x - 1, game->pos.y);
	if (keycode == 1)
		move_to(game, game->pos.x, game->pos.y + 1);
	if (keycode == 2)
		move_to(game, game->pos.x + 1, game->pos.y);
	return (0);
}

int	clean_exit(t_game *game)
{
	free_map(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_args(argc, argv) == 0)
		return (1);
	if (check_file(&game, argv[1]) == 0)
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size.x * 32, \
		game.size.y * 32, "so_long");
	create_images(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, clean_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
