# Compiler and flags
CXX = g++
CXXFLAGS = -std=gnu++17 -Wall -Wextra -pthread

# Target executable
TARGET = server

# Source files
SRCS = server.cpp hashtable.cpp avl.cpp heap.cpp zset.cpp thread_pool.cpp

# Header files (optional, for clarity)
HEADERS = hashtable.h avl.h heap.h zset.h thread_pool.h common.h list.h

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
