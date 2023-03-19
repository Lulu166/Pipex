# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:23:06 by luhumber          #+#    #+#              #
#    Updated: 2023/03/15 18:17:30 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS		+=	--no-print-directory

LIST_OBJS = $(SRCS:.c=.o)

DIR_OBJS = .objs/

SRCS = 	main.c \
		init.c \
		exit.c \
		

OBJS = $(addprefix $(DIR_OBJS), $(LIST_OBJS))
HEADERS = pipex.h

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(HEADERS)
	@$(MAKE) libft
	@cc $(OBJS) $(MLXFLAGS) ./libft/libft.a -o $(NAME)
	@echo "\033[1;33mCompilation terminée 💥\033[0m";
	

$(DIR_OBJS)%.o: %.c  $(HEADERS) Makefile 
		@cc $(CFLAGS) -c $< -o $@ -I.

clean:
	@$(MAKE) fclean -C ./libft/
	@rm -f $(OBJS_BONUS)
	@rm -rf $(DIR_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

libft:
	@$(MAKE) all -C ./libft/

.PHONY: clean fclean re libft

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)