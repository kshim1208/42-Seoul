# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 14:14:47 by kshim             #+#    #+#              #
#    Updated: 2022/07/13 13:41:07 by kshim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUG = 
RM = rm
RMFLAGS = -f

HEADERS = -I$(INCLUDE)

LIBDIR = ./libft

LIBFLAG = -lft

INCLUDE = ./include

SRCSDIR = ./srcs/

BONUS_SRCSDIR = ./srcs_bonus/

SRCS_FILES = ps_main.c ft_ps_parsing.c ft_ps_indexing.c ft_ps_indexing2.c ft_deque.c ft_deque2.c ft_deque3.c ft_ps_utils.c ft_ps_utils2.c ft_ps_utils3.c ft_ps_sorting_main.c ft_ps_sorting_move.c ft_ps_sorting_node_move.c ft_ps_sorting_rev_rotate.c ft_ps_sorting_2_3.c ft_ps_sorting_4.c ft_ps_sorting_5.c ft_ps_sorting_only_main_5.c ft_ps_sorting_only_3_4.c ft_ps_sorting_structs.c ft_ps_sorting_oper_list.c
BONUS_SRCS_FILES = checker_main_bonus.c ft_ps_checker_bonus.c ft_ps_parsing_bonus.c ft_ps_indexing_bonus.c ft_ps_indexing2_bonus.c ft_deque_bonus.c ft_deque2_bonus.c ft_deque3_bonus.c ft_ps_utils_bonus.c ft_ps_utils2_bonus.c ft_ps_utils3_bonus.c ft_ps_sorting_structs_bonus.c ft_ps_sorting_node_move_bonus.c ft_ps_sorting_oper_list_bonus.c get_next_line_bonus.c

SRCS = $(addprefix $(SRCSDIR), $(SRCS_FILES))

BONUS_SRCS = $(addprefix $(BONUS_SRCSDIR), $(BONUS_SRCS_FILES))

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJECTS = $(OBJS)

BONUS_OBJECTS = $(BONUS_OBJS)

$(NAME): $(LIBDIR) $(OBJECTS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) $(DEBUG) -I$(LIBDIR) $(HEADERS) $(OBJECTS) -L$(LIBDIR) $(LIBFLAG) -o $(NAME)

$(CHECKER): $(LIBDIR) $(BONUS_OBJECTS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) $(DEBUG) -I$(LIBDIR) $(HEADERS) $(BONUS_OBJECTS) -L$(LIBDIR) $(LIBFLAG) -o $(CHECKER)

%.o	: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(HEADERS) -I$(LIBDIR) -c $< -o $@

all : $(NAME)

bonus: $(CHECKER)
	
clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME) $(CHECKER)

re: 
	make fclean 
	make all

.PHONY:all bonus clean fclean re
