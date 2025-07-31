# Compiler und Flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = ClapTrap

DEBUG ?= 0

# DEBUG-Flag an die Compiler-Flags anhängen
CXXFLAGS += -DDEBUG=$(DEBUG)

# Quelle(n) für das Programm
SRC =	main.cpp \
		ClapTrap.cpp \

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

