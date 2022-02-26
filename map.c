/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:52:42 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:49:14 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	game->map = malloc(sizeof(char *) * game->size.y);
	if (!game->map)
	{
		ft_printf("Error\n");
		ft_printf("Can't malloc the map\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < game->size.y)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size.y - 1)
	{
		if (ft_strlen(game->map[i]) - 1 != game->size.x)
			return (ft_error("Map must be rectangular"));
		i++;
	}
	if (game->map[i] == NULL || ft_strlen(game->map[i]) != game->size.x)
		return (ft_error("Map must be rectangular"));
	return (1);
}

int	invalid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] != '1'
			&& game->map[i][j] != '0'
			&& game->map[i][j] != 'C'
			&& game->map[i][j] != 'E'
			&& game->map[i][j] != 'P')
				return (ft_error("Invalid character: Valid = [1, 0, C, E, P]"));
			j++;
		}
		i++;
	}
	return (1);
}

int	walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.y)
	{
		j = 0;
		while (j < game->size.x)
		{
			if (game->map[i][j] != '1' && (i == 0 || i == game->size.y - 1
			|| j == 0 || j == game->size.x - 1))
				return (ft_error("Map must be surrounded by walls ('1')"));
			if (game->map[i][j] == 'C')
				game->keys += 1;
			if (game->map[i][j] == 'P')
				game->player += 1;
			if (game->map[i][j] == 'E')
				game->exit += 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	game->keys = 0;
	game->exit = 0;
	game->player = 0;
	game->moves = 0;
	if (rectangular(game) == 0)
		return (0);
	if (invalid_char(game) == 0)
		return (0);
	if (walls(game) == 0)
		return (0);
	if (game->player != 1)
		return (ft_error("Need one and only one player ('P')"));
	if (game->exit == 0)
		return (ft_error("Need at least one exit ('E')"));
	if (game->keys == 0)
		return (ft_error("Need at least one collectible ('C')"));
	return (1);
}
