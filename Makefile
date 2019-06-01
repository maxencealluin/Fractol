# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/06/01 14:28:19 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_NAME =	main.c \
			ft_image.c \
			ft_key_hook.c \
			ft_mouse_hook.c \
			ft_pixel_utils.c \
			ft_expose_hook.c \
			ft_define_fractal.c \
			ft_end.c \
			ft_draw_fractal.c

HEADER_NAME = fractol.h
SRC_PATH = src
OBJ_PATH = obj
HEADER_PATH = includes/
CC = gcc
CCFLAGS =  -Wall -Wextra -Werror -O2 -O3
CPPFLAGS = -I ./libft/includes -I $(HEADER_PATH) -MMD
LIBFLAGS = -L ./libft/ -lft
MLXFLAGS = -I ./minilibx_macos/ ./minilibx_macos/libmlx.a
FRMWORK = -framework OpenGL -framework AppKit
HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos
	$(CC) $(CCFLAGS) -lpthread $(LIBFLAGS) $(MLXFLAGS) $(FRMWORK)  $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
