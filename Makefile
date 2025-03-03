# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 13:24:40 by cmatos-a          #+#    #+#              #
#    Updated: 2025/03/03 14:52:28 by cmatos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIB_NAME = libpipex.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

RM = rm -f
MAKE_CMD = make

INCLUDES_DIR = .
SRCS_DIR = srcs/
OBJ_DIR = obj

SRCS =	$(SRCS_DIR)pipex_utils.c \
		$(SRCS_DIR)pipex.c

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)/%.o)

DEPS = $(INCLUDES_DIR)/pipex.h

all: $(LIBFT) $(LIB_NAME) $(NAME)

$(LIBFT):
	$(MAKE_CMD) -C $(LIBFT_DIR)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

$(NAME): $(LIB_NAME) $(OBJ_DIR)/pipex.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/pipex.o $(LIB_NAME) $(LIBFT) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE_CMD) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(LIB_NAME) $(NAME)
	$(MAKE_CMD) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re