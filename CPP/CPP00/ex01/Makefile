# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:52:30 by jkarras           #+#    #+#              #
#    Updated: 2024/10/25 14:17:30 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler und Flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = phonebook

# Verzeichnisse
SOURCE_DIR = source
CLASSES_SOURCE_DIR = classes/source

# Quelle(n) für das Programm
SRC = $(SOURCE_DIR)/main.cpp \
      $(SOURCE_DIR)/add_contact.cpp \
      $(SOURCE_DIR)/search.cpp \
      $(CLASSES_SOURCE_DIR)/Contact.cpp \
      $(CLASSES_SOURCE_DIR)/PhoneBook.cpp


# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

