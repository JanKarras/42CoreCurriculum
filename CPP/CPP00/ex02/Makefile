# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:52:30 by jkarras           #+#    #+#              #
#    Updated: 2024/10/25 15:00:03 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler und Flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = account

SRC =	tests.cpp \
		Account.cpp \

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

