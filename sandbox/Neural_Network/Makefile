# Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -Wextra `wx-config --cxxflags --libs`

# Top level Source Files
TOP_SRCS := network_tester.cpp
TOP_OBJS := $(TOP_SRCS:%.cpp=build/&.o)

# Source Files from sub directories
SUBDIRS := Activation_Functions Data_Handling Layers Learning_Data Network Training
OUT := network_tester.out

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS) $(TOP_OBJS)
	@echo "Linking all objects into $(OUT)..."
	$(CXX) $(TOP_OBJS) build/*.o -o $(OUT)

# Compile top level source files
build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build sub directories
$(SUBDIRS):
	@$(MAKE) -C $@

# Clean target
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean;	\
	done
	@rm -f build/*.o $(TOP_OBJS) $(OUT)