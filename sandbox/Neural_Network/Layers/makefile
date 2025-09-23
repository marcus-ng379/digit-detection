# Compiler Flags
CXX := g++
CXXFLAGS := -INeural_Network -Wall -Wextra `wx-config --cxxflags --libs`

# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=../build/layers_%.o)

.PHONY: all clean

all: $(OBJS)

# Building all files
../build/layers_%.o: %.cpp
	@mkdir -p ../build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f ../build/layers_*.o