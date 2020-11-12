# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 15:26:07 by chnikia           #+#    #+#              #
#    Updated: 2020/11/11 17:15:07 by chnikia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Werror -Wextra

MLX_LIB_DIR = ./minilibx_mms/
MLX_LIB			= -I$(MLX_LIB_DIR) -L$(MLX_LIB_DIR) -lmlx -framework OpenGL -framework AppKit -lm
MLX	= $(MLX_LIB_DIR)libmlx.dylib

LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR)  -lft

SRC = cub3d \
	init \
	draw \
	parcer \
	errors \
	utils \
	parc_color \
	parc_map \
	parc_tx \
	sprite \
	start_mlx \
	screen \
	move \
	init2 \
	sprite2 \
	parc_map2 \
	drawutil
ADD = $(addsuffix .c, $(addprefix src/, $(SRC)))
ADD += ./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c
OBJS = $(ADD:.c=.o)

all: $(NAME)

make_libft:
	@echo "....... libft is compiling"
	@make bonus -C libft

$(NAME): $(MLX) $(OBJS) make_libft
	@gcc ${CFLAGS}  -I$(LIBFT_DIR) $(LIBFT) ${OBJS} ${MLX_LIB}  -o ${NAME}
	@echo "||||||||| cub3D is compiled! |||||||||\n"
	@echo "༼ つ ◕_◕  GOOD LUCK, HAVE FUN! ༼ つ ◕_◕ \n"


$(MLX):
	@echo "....... libmlx.dylib is compiling\n"
	@make -C $(MLX_LIB_DIR)
	@echo "....... libmlx.dylib is compiled ^_^\n"
	@rm -rf ./libmlx.dylib
	@echo "....... Deleted libmlx.dylib from core dir\n"
	@cp $(MLX_LIB_DIR)libmlx.dylib ./
	@echo "....... New libmlx.dylib copied to core dir\n"

clean:
	@make clean -C $(MLX_LIB_DIR)
	@make fclean -C ./libft
	@rm $(OBJS)

fclean: clean
	@rm libmlx.dylib
	@rm $(NAME)

re: fclean all


%.o: %.c
	@gcc ${CFLAGS} $^ -o $@ -c


.PHONY:	all clean fclean re
