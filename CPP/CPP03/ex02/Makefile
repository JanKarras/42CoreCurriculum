# Compiler und Flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
#CXXFLAGS += -DDEBUG=1
# Zielprogramm
TARGET = FragTrab


# Quelle(n) für das Programm
SRC =	main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

