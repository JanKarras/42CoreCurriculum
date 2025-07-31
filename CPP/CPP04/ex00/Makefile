# Compiler und Flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = Animal


# Quelle(n) für das Programm
SRC =	src/main.cpp \
		src/Dog.cpp \
		src/Animal.cpp \
		src/WrongAnimal.cpp \
		src/Cat.cpp \
		src/WrongCat.cpp \


# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all
