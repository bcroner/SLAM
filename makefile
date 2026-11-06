# Compiler Configuration
CXX = g++
CXXFLAGS = -std=c++17 -O3 -march=native -Wall -Wextra -Iinclude

# Directory Infrastructure
TARGET = validation_tests
SRC_DIR = test/src
OBJ_DIR = obj

# Source and Object Layout
SOURCES = $(SRC_DIR)/validation_tests.cpp
OBJECTS = $(OBJ_DIR)/validation_tests.o

# Default Target Build Sequence
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup Tasks
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
