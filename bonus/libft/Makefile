# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 20:31:33 by lucas             #+#    #+#              #
#    Updated: 2023/02/22 19:07:04 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

LIST_OBJS = $(SRCS:.c=.o)

DIR_OBJS = .objs/

SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strchr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_hexa.c

SRCS_BONUS = 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJS = $(addprefix $(DIR_OBJS), $(LIST_OBJS))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADERS = 	libft.h

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(HEADERS) Makefile
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[1;34mCompilation libft terminée 🥸\033[0m";

$(DIR_OBJS)%.o: %.c  $(HEADERS) Makefile 
		@cc $(CFLAGS) -c $< -o $@ -I.

bonus: $(OBJS_BONUS) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(DIR_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

.PHONY: clean fclean re
	
