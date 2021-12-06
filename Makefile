# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 20:47:46 by lrosby            #+#    #+#              #
#    Updated: 2021/11/28 20:47:48 by lrosby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c	ft_printf_utils.c	ft_printf_more_utils.c

HEADER	=	ft_printf.h
OBJ		= 	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wextra -Werror -Wall -I$(HEADER)

.PHONY	:all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all
