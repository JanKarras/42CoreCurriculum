# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 13:55:21 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 13:55:39 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra

SRCDIR := server
OBJDIR := obj
CONFIG := confic

TARGET := webserv

SOURCES := $(shell find $(SRCDIR) -type f -name "*.cpp")

OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: freeSocket $(TARGET)

freeSocket:
	@./freeSoket.sh

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)   # 🛠 Erstelle das Verzeichnis für die .o-Datei
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

confic: all
	./$(TARGET) $(CONFIG)

re: fclean all

.PHONY: all clean fclean confic re freeSocket
