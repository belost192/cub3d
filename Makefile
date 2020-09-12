NAME = cub3d
HEAD = ./Header/cub3d.h
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = 	get_next_line\
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -rf

%.o : %.c $(HEAD)
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(ARRC) $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(REMF) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(REMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
