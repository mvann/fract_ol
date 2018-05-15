# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 18:23:49 by mvann             #+#    #+#              #
#    Updated: 2018/03/08 16:52:23 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
COMP_FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
MINILIBX_DIR = minilibx_macos/
PTHREAD =  -lpthread
MINILIBX = -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC = fract_ol.c\
draw.c\
keyevents.c\
loop.c\
fractals.c\
colors.c\
helper_functions.c\
draw_info.c

all: $(NAME)

$(NAME):
	@cd libft/ && make
	@cd minilibx_macos/ && make
	@gcc $(COMP_FLAGS) -o $(NAME) $(PTHREAD) $(SRC) $(LIBFT) $(MINILIBX)

test:
	@rm -f $(SRC:.c=.o)
	@rm -f $(NAME)
	@gcc $(COMP_FLAGS) -o $(NAME) $(PTHREAD) $(SRC) $(LIBFT) $(MINILIBX)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean
	@cd $(MINILIBX_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft/ && make fclean

re: fclean all
