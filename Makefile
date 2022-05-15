# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncallie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:36:02 by ncallie           #+#    #+#              #
#    Updated: 2022/03/01 14:36:03 by ncallie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
CC = gcc
RM = rm -f
MAKE = make
READLINE = -L ~/.brew/opt/readline/lib -lreadline
CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3

SRCS =	srcs/main.c \
		srcs/error_msg.c \
		srcs/read_input.c \
		srcs/signal.c \
		srcs/redirections.c \
		srcs/builtins/cd.c \
		srcs/builtins/pwd.c \
		srcs/builtins/echo.c \
		srcs/builtins/env.c \
		srcs/builtins/env_list.c \
		srcs/builtins/export.c \
		srcs/builtins/unset.c \
		srcs/builtins/exit.c \
		srcs/executer/exec_args.c \
		srcs/executer/exec_cmd.c \
		srcs/executer/pipes.c \
		srcs/executer/args_list.c \
		srcs/executer/here_doc.c \
		srcs/lexer/check_args.c \
		srcs/lexer/expand.c \
		srcs/lexer/expand_aux.c \
		srcs/lexer/quotes.c \
		srcs/lexer/split_args.c \
		srcs/lexer/token.c \
		srcs/lexer/check_error_pipes.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s all -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(READLINE) -o $(NAME)
clean:
	@clear
	@$(RM) $(OBJS)
	@$(MAKE) clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libft/libft.a

re: fclean all

.PHONY: all re clean fclean