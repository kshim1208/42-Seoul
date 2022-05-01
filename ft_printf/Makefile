NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = -rcs

HEADERS = -I$(INCLUDE)

LIBFTDIR = ./libft

LIBFT = /libft.a

INCLUDE = ./include

SRCSDIR = ./srcs/

SRCS_FILES = ft_printf.c ft_printf_output_length.c ft_printf_content.c ft_printf_flags.c ft_printf_set_output.c ft_printf_set_data.c ft_printf_utils.c

BONUS_SRCS_FILES = ft_printf_bonus.c ft_printf_output_length_bonus.c ft_printf_content_bonus.c ft_printf_flags_bonus.c ft_printf_set_output_bonus.c ft_printf_set_data_bonus.c ft_printf_utils_bonus.c

SRCS = $(addprefix $(SRCSDIR), $(SRCS_FILES))

BONUS_SRCS = $(addprefix $(SRCSDIR), $(BONUS_SRCS_FILES))

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef DO_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(OBJS)
endif

$(NAME): $(LIBFTDIR) $(OBJECTS)
	make -C $(LIBFTDIR) bonus
	cp $(LIBFTDIR)$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

%.o	: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(HEADERS) -c $< -o $@

all : $(NAME)

bonus: 
	make DO_BONUS=1 all

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY:all bonus clean fclean re
