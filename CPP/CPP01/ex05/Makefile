# Compiler und Flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = harl


# Quelle(n) für das Programm
SRC =	main.cpp \
		Harl.cpp \

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

