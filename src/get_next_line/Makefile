# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 18:55:13 by tlee              #+#    #+#              #
#    Updated: 2024/11/02 21:25:08 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

LIBFT_PATH	= .././libft
LIBFT		= $(LIBFT_PATH)/libft.a

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar rcs
RM 		= rm -f
HEADERS	= get_next_line.h
SRC 	= get_next_line.c

OBJ 	= $(SRC:.c=.o)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) clean
$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all
	@echo "========= Libft Done ! ========="
	
clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)
fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re