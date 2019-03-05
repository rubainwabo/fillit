# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 21:04:01 by rkamegne          #+#    #+#              #
#    Updated: 2018/12/10 14:41:03 by krutten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ft_process_input.c ft_solve.c ft_check_tetrim.c ft_what_tet.c ft_min_max.c  fillit.c ft_seqdel.c\
	ft_seqnew.c
OBJS = ft_solve.o ft_process_input.o ft_check_tetrim.o ft_what_tet.o ft_min_max.o fillit.o ft_seqdel.o\
		ft_seqnew.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -c $(SRCS) -Ilibft/libft.h -Ifillit.h
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft


clean:	
	@/bin/rm -f $(OBJS)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean clean all

.PHONY: clean fclean all re
