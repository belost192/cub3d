# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:07:54 by chnikia           #+#    #+#              #
#    Updated: 2020/08/05 14:36:09 by chnikia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c  ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCB = ft_lstnew.c ft_lstsize.c ft_lstadd_back.c
OBJS = $(SRCS:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)
COMP = gcc
FlAG = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -f
NORM = norminette

%.o : %.c
	$(COMP) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	@echo Library is done

bonus: $(OBJS) $(OBJB)
	$(ARRC) $(NAME) $(OBJS) $(OBJB)
	@echo Library with bonus functions is done

clean:
	$(REMF) $(OBJS) $(OBJB)
	@echo Objects removed

fclean: clean
	$(REMF) $(NAME)
	@echo Objects and library removed

re: fclean all

norm:
	@$(NORM) $(SRCS) $(SRCB) $(HEAD)

.PHONY: all bonus clean fclean re norm
