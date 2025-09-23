# Compiler Flags
CXX := g++
CXXFLAGS := -Wall -Wextra `wx-config --cxxflags --libs`

# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=../build/data_handling_%.o)

.PHONY: all clean

all: $(OBJS)

# Building all files
../build/data_handling_%.o: %.cpp
	@mkdir -p ../build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f ../build/data_handling_*.o