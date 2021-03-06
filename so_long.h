/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:59:38 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:47:14 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

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
	int		keys;
	int		exit;
	int		player;
}				t_game;

char	*check_input(int fd);
int		find_newline(char *temp);
char	*return_string(char *temp);
char	*move_front(char *temp);
char	*get_next_line(int fd);

char	*free_string(char *str);
char	*concat_temp(char *buff, char *temp);
char	*concat(char *buff, char *temp);
char	*return_line(char **line, char **temp);

void	ft_putnbr(int nb, int *i);
void	ft_unsigned(unsigned int nb, int *i);
void	ft_hex(unsigned int nb, int *i);
void	ft_hexu(unsigned int nb, int *i);
void	ft_pointer(unsigned long p, int *i);

void	ft_conversion(char c, va_list ap, int *i);
void	ft_conversion2(char c, va_list ap, int *i);
int		ft_printf(const char *fmt, ...);

void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i);

int		check_args(int argc, char **argv);
int		find_newlines(int fd);
int		check_file(t_game *game, char *file);

int		ft_error(char *str);
void	free_map(t_game *game);

int		ft_strlen(const char *s);

void	put_image(t_game *game, int i, int j);
void	img_to_map(t_game *game);
void	create_images(t_game *game);

int		create_map(t_game *game, char *file);
int		check_map(t_game *game);

void	move_to(t_game *game, int i, int j);

int		key_hook(int keycode, t_game *game);
int		clean_exit(t_game *game);

#endif