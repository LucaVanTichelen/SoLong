# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 11:00:12 by lvan-tic          #+#    #+#              #
#    Updated: 2022/02/26 12:42:02 by lvan-tic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	gnl/get_next_line_utils.c	\
			gnl/get_next_line.c			\
			printf/ft_numbers.c			\
			printf/ft_printf.c			\
			printf/ft_putstr.c			\
			check.c						\
			error.c						\
			ft_strlen.c					\
			images.c					\
			map.c						\
			move.c						\
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