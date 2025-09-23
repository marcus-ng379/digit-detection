# Compiler Flags
CXX := g++
CXXFLAGS := -Wall -Wextra `wx-config --cxxflags --libs`

# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=../build/learning_data_%.o)

.PHONY: all clean

all: $(OBJS)

# Building all files
../build/learning_data_%.o: %.cpp
	@mkdir -p ../build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f ../build/learning_data_*.o