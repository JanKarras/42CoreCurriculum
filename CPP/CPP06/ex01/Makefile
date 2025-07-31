# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 13:26:10 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 13:26:10 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Serializer
CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98
SRCDIR := ./src ./classes/AbstractClasses/src ./classes/ExceptionClasses/src ./classes/UsableClasses/src ./classes/DataClasses/src
OBJDIR := ./obj

SRC := $(shell find $(SRCDIR) -name "*.cpp")

OBJ := $(patsubst ./src/%.cpp, $(OBJDIR)/src/%.o, $(filter ./src/%, $(SRC)))
OBJ += $(patsubst ./classes/AbstractClasses/src/%.cpp, $(OBJDIR)/classes/AbstractClasses/src/%.o, $(filter ./classes/AbstractClasses/src/%, $(SRC)))
OBJ += $(patsubst ./classes/ExceptionClasses/src/%.cpp, $(OBJDIR)/classes/ExceptionClasses/src/%.o, $(filter ./classes/ExceptionClasses/src/%, $(SRC)))
OBJ += $(patsubst ./classes/UsableClasses/src/%.cpp, $(OBJDIR)/classes/UsableClasses/src/%.o, $(filter ./classes/UsableClasses/src/%, $(SRC)))
OBJ += $(patsubst ./classes/DataClasses/src/%.cpp, $(OBJDIR)/classes/DataClasses/src/%.o, $(filter ./classes/DataClasses/src/%, $(SRC)))

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
RESET := \033[0m

.PHONY: all clean fclean re debug valgrind execute

all: $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $< into $@$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

debug: CFLAGS += -DDEBUG=1

debug: re
	@echo "$(GREEN)Build with DEBUG enabled!$(RESET)"

valgrind: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)All object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

execute: $(NAME)
	@./$(NAME)
	@echo "$(GREEN)Program executed successfully!$(RESET)"
