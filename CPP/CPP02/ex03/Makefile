# Compiler und Flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Zielprogramm
TARGET = bsp


# Quelle(n) für das Programm
SRC =	main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp \

# Regel zum Kompilieren des Programms
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Regel zum Aufräumen
clean:
	rm -f $(TARGET)

# Regel zum Neuaufbau
re: clean all

