# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:37:10 by rmatthes          #+#    #+#              #
#    Updated: 2025/07/28 14:20:15 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

OBJ_DIR = obj

SRCS = \
	src/execute_utils.c \
	src/execute.c \
	src/ft_push_swap.c \
	src/ft_strcmp.c \
	src/get_calls.c \
	src/getter_utils.c \
	src/main_utils.c \
	src/main.c \
	src/sort_big_amount.c \
	src/sort_small_amount.c \
	src/operations/push_a.c \
	src/operations/push_b.c \
	src/operations/reverse_rotate_a_b.c \
	src/operations/reverse_rotate_a.c \
	src/operations/reverse_rotate_b.c \
	src/operations/rotate_a_b.c \
	src/operations/rotate_a.c \
	src/operations/rotate_b.c \
	src/operations/swap_a_b.c \
	src/operations/swap_a.c \
	src/operations/swap_b.c \

BONUS_SRCS = \
	push_swap_bonus/src/swap_b_bonus.c \
	push_swap_bonus/src/ckeck_bonus.c \
	push_swap_bonus/src/get_next_line_bonus/get_next_line_bonus.c \
	push_swap_bonus/src/get_next_line_bonus/get_next_line_utils_bonus.c \
	push_swap_bonus/src/ft_strcmp_bonus.c \
	push_swap_bonus/src/get_functions_array_bonus.c \
	push_swap_bonus/src/main_bonus.c \
	push_swap_bonus/src/main_utils_bonus.c \
	push_swap_bonus/src/push_a_bonus.c \
	push_swap_bonus/src/push_b_bonus.c \
	push_swap_bonus/src/reverse_rotate_a_b_bonus.c \
	push_swap_bonus/src/reverse_rotate_a_bonus.c \
	push_swap_bonus/src/reverse_rotate_b_bonus.c \
	push_swap_bonus/src/rotate_a_b_bonus.c \
	push_swap_bonus/src/rotate_a_bonus.c \
	push_swap_bonus/src/rotate_b_bonus.c \
	push_swap_bonus/src/swap_a_b_bonus.c \
	push_swap_bonus/src/swap_a_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
BONUS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJS))

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
MKDIR_P = mkdir -p


$(OBJ_DIR)/%.o: %.c
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Compiling libft..."
	@make -C libft > /dev/null
	@echo "Compiling push_swap objects..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) libft/libft.a
	@echo "push_swap executable created."

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_FILES)
	@echo "Compiling libft for bonus..."
	@make -C libft > /dev/null
	@echo "Compiling checker bonus objects..."
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ_FILES) libft/libft.a
	@echo "checker executable created."

clean:
	@echo "Cleaning object files..."
	$(RM) $(OBJ_DIR)
	@make -C libft clean > /dev/null

fclean: clean
	@echo "Removing executables..."
	$(RM) $(NAME) $(BONUS_NAME)
	@make -C libft fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re bonus
