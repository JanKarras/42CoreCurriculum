# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:02:37 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 13:48:16 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell
CFLAGS      = -Wall -Wextra -Werror
CC          = cc
SRC_DIR     = source
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = libft/libft.a
RM          = rm -rf

SRC_BUILTINS_DIR = $(SRC_DIR)/builtins
SRC_EXECUTE_DIR  = $(SRC_DIR)/execute
SRC_FD_DIR       = $(SRC_DIR)/fd
SRC_HANDLE_DIR   = $(SRC_DIR)/handle
SRC_MAIN_DIR     = $(SRC_DIR)/main
SRC_PARSE_DIR    = $(SRC_DIR)/parse
SRC_PROCESS_DIR  = $(SRC_DIR)/process
SRC_UTILS_DIR    = $(SRC_DIR)/utils
SRC_HEREDOC_DIR    = $(SRC_DIR)/heredoc

SRC =   $(SRC_MAIN_DIR)/main.c \
        $(SRC_BUILTINS_DIR)/cd.c \
        $(SRC_BUILTINS_DIR)/check_builtin.c \
        $(SRC_BUILTINS_DIR)/echo.c \
        $(SRC_BUILTINS_DIR)/env.c \
        $(SRC_BUILTINS_DIR)/exit.c \
        $(SRC_BUILTINS_DIR)/export.c \
        $(SRC_BUILTINS_DIR)/pwd.c \
        $(SRC_BUILTINS_DIR)/unset.c \
        $(SRC_EXECUTE_DIR)/execute.c \
        $(SRC_HANDLE_DIR)/error.c \
        $(SRC_HANDLE_DIR)/signal.c \
        $(SRC_PARSE_DIR)/del_quotes.c \
        $(SRC_PARSE_DIR)/expand.c \
        $(SRC_PARSE_DIR)/nodes.c \
        $(SRC_PARSE_DIR)/pathfinder.c \
        $(SRC_PARSE_DIR)/split_cmd.c \
        $(SRC_PARSE_DIR)/split_spaces.c \
        $(SRC_PROCESS_DIR)/input.c \
        $(SRC_UTILS_DIR)/array.c \
        $(SRC_UTILS_DIR)/free.c \
        $(SRC_UTILS_DIR)/utils.c \
        $(SRC_UTILS_DIR)/utils_wait.c \
        $(SRC_FD_DIR)/fd_create.c \
        $(SRC_HEREDOC_DIR)/heredoc.c \
        $(SRC_HEREDOC_DIR)/process_heredoc.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo "Compiling minishell..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $@
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/**/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Fcleaning..."
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean
	@make all

.PHONY: all clean fclean re
