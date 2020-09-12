NAME = mlx
CC = gcc
SOURSE = mlx.c
OBJ = $(SOURSE:.c=.o)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
