NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g
RM = rm
RMFLAGS = -f

HEADERS = -I$(INCLUDE)

LIBDIR = ./libft

LIBFLAG = -lft

INCLUDE = ./includes

SRCSDIR = ./srcs/

SRCS_FILES = ps_main.c funcs_argv.c ft_deque.c push_swap_util.c

BONUS_SRCS_FILES =

SRCS = $(addprefix $(SRCSDIR), $(SRCS_FILES))

BONUS_SRCS = $(addprefix $(SRCSDIR), $(BONUS_SRCS_FILES))

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef DO_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(OBJS)
endif

$(NAME): $(LIBDIR) $(OBJECTS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) $(DEBUG) -L $(LIBDIR) $(LIBFLAG) $(OBJECTS) -o $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(HEADERS) -c $< -o $@

all : $(NAME)

bonus: 
	make DO_BONUS=1 all

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: 
	make fclean 
	make all

.PHONY:all bonus clean fclean re
