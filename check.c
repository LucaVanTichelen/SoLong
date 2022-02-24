/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:29 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/24 16:34:05 by lvan-tic         ###   ########.fr       */
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

int	find_newlines(int fd)
{
	int		i;
	int		nl;
	char	c;

	nl = 0;
	i = read(fd, &c, 1);
	while (i != 0)
	{
		if (i == -1)
		{
			printf("Error\n");
			printf("Can't read file\n");
			return (-1);
		}
		if (c == '\n')
			nl++;
		i = read(fd, &c, 1);
	}
	return (nl);
}

int	check_file(t_game *game, char *file)
{
	int		fd;
	int		nl;

	game->moves = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		perror(file);
		return (0);
	}
	nl = find_newlines(fd);
	if (nl == -1)
		return (0);
	return (1);
}
