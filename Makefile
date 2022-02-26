# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 11:00:12 by lvan-tic          #+#    #+#              #
#    Updated: 2022/02/26 12:00:10 by lvan-tic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	check.c					\
			error.c					\
			ft_strlen.c				\
			get_next_line_utils.c	\
			get_next_line.c			\
			images.c				\
			map.c					\
			move.c					\
			so_long.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -lmlx -framework OpenGL -framework AppKit

clean	:	
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all