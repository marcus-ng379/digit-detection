cmake_minimum_required(VERSION 3.16)
project(Digit_Detection)
set(CMAKE_CXX_STANDARD 17)

option(USE_SYSTEM_WXWIDGETS "Use system-installed wxWidgets" ON)

# Add ALL .cpp executable under src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_executable(Digit_Detection ${SOURCES})

# Include your own headers
target_include_directories(Digit_Detection PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# wxWidgets integration
if(USE_SYSTEM_WXWIDGETS)
    find_package(wxWidgets REQUIRED COMPONENTS core base)
    include(${wxWidgets_USE_FILE})
    target_link_libraries(Digit_Detection PRIVATE ${wxWidgets_LIBRARIES})
else()
    # Build wxWidgets from submodule
    set(wxBUILD_SHARED OFF CACHE BOOL "" FORCE)
    set(wxBUILD_GUI ON CACHE BOOL "" FORCE)
    add_subdirectory(lib/wxWidgets)
    target_link_libraries(Digit_Detection PRIVATE wx::core wx::base)
endif()
