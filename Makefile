# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Amber <Amber@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 13:40:29 by Amber             #+#    #+#              #
#    Updated: 2020/05/07 16:11:04 by Amber            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

FLAGS = -Wall -Werror -Wextra -g

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

LIB_PATH = ./libft
LIB_LINK = -I $(LIB_PATH) -L $(LIB_PATH) -lft

INC_PATH = ./include

$(NAME):
	@make -C $(MLX_PATH)
	@make -C $(LIB_PATH)
	@gcc $(FLAGS) -c ./src/*.c -I $(INC_PATH)/*.h
	@gcc $(MLX_LINK) $(LIB_LINK) ./*.o -o $(NAME)
	
all: $(NAME)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(INC_PATH)/*.gch
	@rm -f *.o

fclean: clean
	@make clean -C $(MLX_PATH)
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)	

re: fclean all

.PHONY: all clean fclean re