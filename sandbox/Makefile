# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra `wx-config --cxxflags --libs`

# Source files
SRC = main.cpp wxwidget/window.cpp
OUT = sandbox.out

# Default target
run: $(OUT)
	@./$(OUT)
	@$(MAKE) clean

# Build target
$(OUT): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

# Clean target
clean:
	rm -f $(OUT)
