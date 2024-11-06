# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:48:35 by tlee              #+#    #+#              #
#    Updated: 2024/11/02 19:00:55 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Create a new variable "NAME", which will contain the name of the output file we
#want to obtain at the end of the Makefile execution
NAME 	= libft.a

#Program for compiling C programs;
CC 		= cc

##Create a variable called 'CFLAGS', flags used to give to the C compiler
CFLAGS 	= -Wall -Wextra -Werror

#Create a variable called 'AR'
#command ar - to create an archive file, which becomes a static library
#r - replace, c - create, s - statics
AR 		= ar rcs

#Create a variable called 'RM', which remove files 
#-f without prompting for confirmation
RM 		= rm -f

HEADERS	= libft.h

SRC 	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
		  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

#Create a variable "OBJ", which created the list of obj files from every c files
#listed in 'SRC'
OBJ 	= $(SRC:.c=.o)

#any file ending with .o depend on all the .c file and header file
#Below is the recipe assciated with the rule, -c generate object file
#$< representing the first prerequisite (%.c)
#-o $@ specifies the output file of the target object file(%.o)
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

#target 'all' checks if the file specified in the 'NAME' variable exists
#if it doesn't, the Makefile moves to the next line to start creating the file
#after the file is created, the 'clean' target is used to delete all .o files
#ranlib will be invoked to generate an index for the static library specified 
#by the variable $(NAME). This index helps in speeding up the linking process 
#when the library is used in other parts of the project.
all: $(NAME) clean

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

#Used to delete all files with the '.o' extension
clean:
	@$(RM) $(OBJ)

#'fclean' depends on the 'clean' target.
#It first runs "make clean" to remove all object files, and then removes the
#library file specified in the $(NAME) variable
fclean: clean
	@$(RM) $(NAME)

#To rebuild, first delete all '.o' files and library file and then start a fresh
#library using the $(NAME) target  
re: fclean all

#Represent actions that can be perfomed by make
.PHONY: all clean fclean re

