# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:34:38 by tlee              #+#    #+#              #
#    Updated: 2024/07/16 20:49:21 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_PATH	= ../libft

LIBFT		= $(LIBFT_PATH)/libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

HEADERS		= ft_printf.h

SRC			= ft_printf.c ft_printf_percent.c ft_printf_char.c ft_printf_str.c\
				ft_printf_int.c ft_printf_unsigned.c ft_printf_hex.c\
				ft_printf_pointer.c

OBJ 		= $(SRC:.c=.o)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) clean

#libftprintf depends on '$(LIBFT)' and '$(OBJ)', copy the contents of '$(LIBFT)'
#to '$(NAME)'. Then creates/modifies the static library '$(NAME)' by adding the 
#object files '$(OBJ)'
$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	
$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@echo "========= Libft Done ! ========="

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
