# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:29:02 by srouhe            #+#    #+#              #
#    Updated: 2020/01/06 00:48:38 by srouhe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	minishell
C		= 	gcc
FLAGS 	= 	-Wall -Werror -Wextra

FILES 	=	main.c \
			input.c \
			prompt.c \
			utils_env.c \
			setenv.c \
			unsetenv.c \
			recoverenv.c \
			signal.c \
			exec.c \
			echo.c \
			cd.c \
			misc.c

SRCS 	=	$(addprefix srcs/, $(FILES))
OBJS 	=	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(C) $(FLAGS) -o $(NAME) $(SRCS) -I includes/ -I libft/includes -Llibft -lft

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
