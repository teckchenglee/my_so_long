# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 20:34:52 by tlee              #+#    #+#              #
#    Updated: 2024/11/07 21:21:21 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

OBJ_PATH 		= obj/

LIBFT_PATH		= ./src/libft
LIBFT			= $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH	= ./src/ft_printf
FT_PRINTF		= $(FT_PRINTF_PATH)/libftprintf.a

GNL_PATH		= ./src/get_next_line
GNL				= $(GNL_PATH)/get_next_line.a

MLX_PATH		= ./minilibx-linux
MLX 			= $(MLX_PATH)/libmlx.a

UNTAR			= tar -xzf

MLX_INCLUDE 	= -I/usr/include -Imlx_linux -O3
MLX_FLAGS 		= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_TAR 		= minilibx-linux

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDES		= -I . -I$(LIBFT_PATH) -I$(GNL_PATH) -I$(MLX_INCLUDE)

AR				= ar rcs
RM				= rm -f

HEADERS			= so_long.h
SRC 			= so_long.c utils_map.c utils_display.c utils_exit.c \
					utils_move.c

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

DOWNLOAD_URL = https://cdn.intra.42.fr/document/document/26192/minilibx-linux.tgz
untar:
	@if [ ! -f "$(MLX_TAR).tgz" ]; then \
		echo "${BLUE}Downloading $(MLX_TAR)${NC}..."; \
		curl -LO $(DOWNLOAD_URL); \
	fi
	@echo "${BLUE}$(MLX_TAR)${NC} Unpacking... \c"
	@$(UNTAR) $(MLX_TAR).tgz > /dev/null
	@echo "${GREEN}Unpacked ${NC}"

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@ 

$(NAME):  $(OBJS)
	@make -sC $(LIBFT_PATH)
	@make -sC $(GNL_PATH)
	@make -sC $(FT_PRINTF_PATH)
	@make -sC $(MLX_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(GNL) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "\e[1;36m \n $(NAME) file created successfully\e[0m"
	@echo "Command to run the program, ./so_long <map files>"
	@echo "Eg ./so_long maps/small.ber\n"

clean:
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(GNL_PATH) clean
	@make -sC $(FT_PRINTF_PATH) clean
	@make -sC $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@make -sC $(GNL_PATH) fclean
	@make -sC $(FT_PRINTF_PATH) fclean
	@make -sC $(MLX_PATH) clean
	@$(RM) $(NAME)
	@rm -rf $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re