# Compiler Flags
CXX := g++
CXXFLAGS := -Wall -Wextra `wx-config --cxxflags --libs`

# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=../build/activation_functions_%.o)

.PHONY: all clean

all: $(OBJS)

# Building all files
../build/activation_functions_%.o: %.cpp
	@mkdir -p ../build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f ../build/activation_functions_*.o