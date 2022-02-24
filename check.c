/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:29 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/24 15:50:27 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		printf("Error\n");
		printf("Invalid number of arguments: Expected 2 got %i\n", argc);
		printf("Use: ./so_long map.ber\n");
		return (0);
	}
	i = ft_strlen(argv[1]);
	if (i < 5 || argv[1][i - 4] != '.' || argv[1][i - 3] != 'b'
	|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
	{
		printf("Error\n");
		printf("Invalid file: %s -> Expected .ber file\n", argv[1]);
		return (0);
	}
	return (1);
}

int	check_file(t_game *game, char *file)
{
	int	fd;

	game->moves = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		perror(file);
		return (0);
	}
	return (1);
}