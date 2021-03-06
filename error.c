/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:53 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:44:54 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size.y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
