/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:59:25 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 11:29:00 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_loop(game.mlx);
	return (0);
}
