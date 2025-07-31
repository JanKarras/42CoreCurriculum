# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:52:30 by jkarras           #+#    #+#              #
#    Updated: 2024/10/24 14:16:53 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile für das Megaphone-Programm

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone

# Quelle(n) für das Programm
SRC = megaphone.cpp

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all
