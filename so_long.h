/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:59:38 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/24 15:49:48 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_win {
	void	*win_ptr;
	t_pos	size;
}				t_win;

typedef struct s_img {
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_game {
	void	*mlx_ptr;
	char	**map;
	t_win	window;
	t_img	wall;
	t_img	grass;
	t_img	key;
	t_img	chest;
	t_img	pirate;
	t_pos	pos;
	int		moves;
	int		keys;
}				t_game;

int		check_args(int argc, char **argv);
int		check_file(t_game *game, char *file);

void	ft_error(char *str);

int		ft_strlen(const char *s);

char	*check_input(int fd);
int		find_newline(char *temp);
char	*return_string(char *temp);
char	*move_front(char *temp);
char	*get_next_line(int fd);

char	*free_string(char *str);
char	*concat_temp(char *buff, char *temp);
char	*concat(char *buff, char *temp);
char	*return_line(char **line, char **temp);

#endif