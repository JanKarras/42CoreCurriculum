# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 13:13:48 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 13:13:53 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = Animal

SRC =	src/main.cpp \
		src/Dog.cpp \
		src/Animal.cpp \
		src/WrongAnimal.cpp \
		src/Cat.cpp \
		src/WrongCat.cpp \
		src/Brain.cpp \


all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

re: clean all
