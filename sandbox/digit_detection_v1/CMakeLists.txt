cmake_minimum_required(VERSION 3.16)
project(Digit_Detection) # Project/Exe name
set(CMAKE_CXX_STANDARD 17)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add executable FIRST
add_executable(Digit_Detection
    src/main.cpp
    src/wxwidget/window.cpp
    src/neural/Activations.cpp
)

# THEN set target properties
target_include_directories(Digit_Detection PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Digit_Detection ${wxWidgets_LIBRARIES})