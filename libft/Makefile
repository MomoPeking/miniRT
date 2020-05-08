# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Amber <Amber@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:38:51 by qdang             #+#    #+#              #
#    Updated: 2020/05/04 20:36:42 by Amber            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HED = libft.h get_next_line.h

SRC = ft_memalloc.c ft_memset.c ft_memcpy.c ft_bzero.c ft_strnew.c \
		ft_strlen.c ft_strnew.c ft_strjoin.c ft_strdup.c ft_strchr.c \
		ft_strsub.c ft_strcmp.c ft_strsplit.c \
		ft_power.c \
		ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c \
		ft_atoi.c ft_atof.c \
		ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

GCH = $(HED:.h=.h.gch)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HED)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(GCH)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re