# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 10:20:32 by cmatos-a          #+#    #+#              #
#    Updated: 2025/02/12 15:28:44 by cmatos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = .
GNL_DIR = .
PRINTF_DIR = .
INCLUDES_DIR = .

SRCS = $(SRCS_DIR)/ft_isalpha.c \
       $(SRCS_DIR)/ft_isdigit.c \
       $(SRCS_DIR)/ft_isalnum.c \
       $(SRCS_DIR)/ft_isascii.c \
       $(SRCS_DIR)/ft_isprint.c \
       $(SRCS_DIR)/ft_strlen.c \
       $(SRCS_DIR)/ft_memset.c \
       $(SRCS_DIR)/ft_bzero.c \
       $(SRCS_DIR)/ft_memcpy.c \
       $(SRCS_DIR)/ft_memmove.c \
       $(SRCS_DIR)/ft_strlcpy.c \
       $(SRCS_DIR)/ft_strlcat.c \
       $(SRCS_DIR)/ft_toupper.c \
       $(SRCS_DIR)/ft_tolower.c \
       $(SRCS_DIR)/ft_strchr.c \
       $(SRCS_DIR)/ft_strrchr.c \
       $(SRCS_DIR)/ft_strncmp.c \
       $(SRCS_DIR)/ft_memchr.c \
       $(SRCS_DIR)/ft_memcmp.c \
       $(SRCS_DIR)/ft_strnstr.c \
       $(SRCS_DIR)/ft_atoi.c \
       $(SRCS_DIR)/ft_strdup.c \
       $(SRCS_DIR)/ft_calloc.c \
       $(SRCS_DIR)/ft_substr.c \
       $(SRCS_DIR)/ft_strjoin.c \
       $(SRCS_DIR)/ft_putstr_fd.c \
       $(SRCS_DIR)/ft_putchar_fd.c \
       $(SRCS_DIR)/ft_putnbr_fd.c \
       $(SRCS_DIR)/*ft_strtrim.c \
       $(SRCS_DIR)/ft_putendl_fd.c \
       $(SRCS_DIR)/ft_striteri.c \
       $(SRCS_DIR)/ft_strmapi.c \
       $(SRCS_DIR)/ft_itoa.c \
       $(SRCS_DIR)/ft_split.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c \
		$(PRINTF_DIR)/ft_printchar.c \
		$(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_printhexa.c \
		$(PRINTF_DIR)/ft_printnbr.c \
		$(PRINTF_DIR)/ft_printptr.c \
		$(PRINTF_DIR)/ft_printstr.c \
		$(PRINTF_DIR)/ft_printunsignd.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelonde.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)  
	ar rcs $(NAME) $(OBJS)
	
BONUS: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean
	make && make bonus
