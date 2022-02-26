/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:59:38 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 11:20:25 by lvan-tic         ###   ########.fr       */
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

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	wall;
	t_img	grass;
	t_img	key;
	t_img	chest;
	t_img	pirate;
	t_pos	size;
	t_pos	pos;
	int		moves;
	int		collectibles;
	int		exit;
	int		player;
}				t_game;

int		check_args(int argc, char **argv);
int		find_newlines(int fd);
int		check_file(t_game *game, char *file);

int		ft_error(char *str);
void	free_map(t_game *game);

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

void	put_image(t_game *game, int i, int j);
void	img_to_map(t_game *game);
void	create_images(t_game *game);

int		create_map(t_game *game, char *file);
int		check_map(t_game *game);

#endif