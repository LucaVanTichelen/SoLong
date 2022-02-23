/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:59:38 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/23 10:53:08 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

char	*check_input(int fd, int BUFFER_SIZE);
int		find_newline(char *temp);
char	*return_string(char *temp);
char	*move_front(char *temp);
char	*get_next_line(int fd);
char	*free_string(char *str);
char	*concat_temp(char *buff, char *temp);
char	*concat(char *buff, char *temp);
char	*return_line(char **line, char **temp);

#endif