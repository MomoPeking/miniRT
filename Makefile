# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Amber <Amber@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 13:40:29 by Amber             #+#    #+#              #
#    Updated: 2020/04/30 15:50:26 by Amber            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

FLAGS = -Wall -Werror -Wextra

HED = ./include/miniRT.h

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@make -C $(MLX_PATH)
	@gcc $(FLAGS) -c *.c -I $(HED)
	@gcc $(MLX_LINK) *.o -o $(NAME)
	
all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@make clean -C $(MLX_PATH)
	@rm -f $(NAME)
	
re: fclean all