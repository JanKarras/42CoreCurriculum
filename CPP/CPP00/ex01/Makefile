# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:52:30 by jkarras           #+#    #+#              #
#    Updated: 2025/07/31 12:50:15 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = phonebook

SOURCE_DIR = source
CLASSES_SOURCE_DIR = classes/source

SRC = $(SOURCE_DIR)/main.cpp \
	  $(SOURCE_DIR)/add_contact.cpp \
	  $(SOURCE_DIR)/search.cpp \
	  $(CLASSES_SOURCE_DIR)/Contact.cpp \
	  $(CLASSES_SOURCE_DIR)/PhoneBook.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

re: clean all

