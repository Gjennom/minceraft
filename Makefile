CC = g++ -std=c++17
LDFLAGS = -lraylib

TARGET = cube.exe
SRC = cube.cpp cube_functions.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp cube.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
