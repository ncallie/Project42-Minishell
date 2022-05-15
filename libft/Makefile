# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncallie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:39:54 by ncallie           #+#    #+#              #
#    Updated: 2022/03/01 15:01:06 by ncallie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_bzero.c ft_memcpy.c ft_strlcpy.c \
		 ft_strlen.c ft_strchr.c ft_strncmp.c ft_strlcat.c \
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		 ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_split.c \
		 ft_lstnew.c  ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c \
		 ft_lstclear.c  ft_new_node.c ft_strcmp.c ft_lstdup.c \
		 free_matrix.c ft_strjoin3.c list_to_matrix.c matrix_len.c \
		 matrix_dup.c del_str_pos.c ft_lst_sort.c ft_lst_free.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean

