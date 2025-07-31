# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:02:37 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 13:42:50 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d
CFLAGS      = -Wall -Wextra -Werror
CC          = cc
SRC_DIR     = source
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = libft/libft.a
RM          = rm -rf
MLX_DIR		= mlx
MLX			= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS	= -lX11 -lXext
MATH_LIB	= -lm

SRC_MAIN_DIR    = $(SRC_DIR)/main
SRC_INIT_DIR	= $(SRC_DIR)/init_data
SRC_PARSE_DIR	= $(SRC_DIR)/parse
SRC_CHECK_DIR	= $(SRC_DIR)/check
SRC_CLEAN_DIR	= $(SRC_DIR)/clean
SRC_GET_FILE_DATA_DIR	= $(SRC_DIR)/clean
SRC_RENDER_DIR	= $(SRC_DIR)/render
SRC_RAYCAST_DIR	= $(SRC_DIR)/raycast
SRC_MOVEMENT_DIR	= $(SRC_DIR)/movement

SRC =   $(SRC_MAIN_DIR)/main.c \
		$(SRC_INIT_DIR)/init_data.c \
		$(SRC_INIT_DIR)/init_mlx.c \
		$(SRC_INIT_DIR)/init_textures.c \
		$(SRC_PARSE_DIR)/parse_args.c \
		$(SRC_CHECK_DIR)/check_arg.c \
		$(SRC_CHECK_DIR)/check_spaces_map.c \
		$(SRC_CHECK_DIR)/check_file_suffix.c \
		$(SRC_CHECK_DIR)/check_tex_paths.c \
		$(SRC_CHECK_DIR)/check_colors.c \
		$(SRC_CLEAN_DIR)/clean_file.c \
		$(SRC_CLEAN_DIR)/check_walls.c \
		$(SRC_CHECK_DIR)/check_map.c \
		$(SRC_CLEAN_DIR)/clean_empty_lines.c \
		$(SRC_GET_FILE_DATA_DIR)/get_file_data.c \
		$(SRC_GET_FILE_DATA_DIR)/get_color.c \
		$(SRC_GET_FILE_DATA_DIR)/get_tex_info.c \
		$(SRC_GET_FILE_DATA_DIR)/get_tex_paths.c \
		$(SRC_GET_FILE_DATA_DIR)/get_map.c \
		$(SRC_GET_FILE_DATA_DIR)/set_player_start.c \
		$(SRC_RENDER_DIR)/render_images.c \
		$(SRC_RAYCAST_DIR)/raycast.c \
		$(SRC_RAYCAST_DIR)/raycast_utils.c \
		$(SRC_MOVEMENT_DIR)/movement.c \
		$(SRC_MOVEMENT_DIR)/movement_utils.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@echo "Compiling minishell..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MATH_LIB) -o $@
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/**/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "Compiling mlx..."
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Fcleaning..."
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

re: fclean
	@make all

.PHONY: all clean fclean re
