# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:52:45 by ismelich          #+#    #+#              #
#    Updated: 2020/03/31 10:21:40 by ismelich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_printf.c modifie.c help_func.c display_char.c convert.c \
display_str.c display_uint.c display_pointer.c display_hex.c \
display_octal.c display_int.c help_func_2.c display_float_1.c \
display_float_2.c ft_strdup.c ft_strncpy.c ft_strncat.c ft_strcat.c \
ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strnew.c \
ft_strsub.c ft_strcpy.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_strndup.c ft_itoa.c ft_strmap.c ft_strmapi.c ft_strcmp.c \
ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_tolower.c \
ft_toupper.c ft_isprint.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
ft_memcmp.c ft_strequ.c ft_strnequ.c ft_putchar.c ft_putstr.c \
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_putendl.c ft_putendl_fd.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memccpy.c ft_memmove.c ft_memchr.c ft_memalloc.c ft_memdel.c \
ft_strclr.c ft_strdel.c ft_striter.c ft_striteri.c ft_strlcat.c \
ft_strlen.c ft_isblank.c ft_islower.c ft_isupper.c ft_words_counter.c \
get_next_line.c ft_abs.c ft_itoa_base.c ft_itoa_base_upper.c \
ft_toupper_str.c ft_nbrlen.c

INC = -I ./includes/

FLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRC))
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[01;33mCompilation of \033[0m\033[36m$(notdir $<)\033[1;32m is done.\033[1;32m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re