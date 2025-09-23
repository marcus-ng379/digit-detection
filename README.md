# Digit Detection

A C++ application for recognizing handwritten digits with neural network using wxWidgets for GUI rendering.

# Requirements
Make sure you have Ubuntu Version 24.04 or above!

## Installation

To install wxWidgets on Ubuntu:   
1. Update your system apt:
```bash
sudo apt update
sudo apt upgrade
```

2. Build all dependecies and Tools required for using CMake and C++.
```bash
sudo apt install build-essential libgtk-3-dev pkg-config bzip2
``` 

3. Extract and Build wxWidgets Locally
```bash
cd extern
tar -xjf wxWidgets-3.2.8.tar.bz2 # Extract wxWidget
cd wxWidgets-3.2.8 # Locate wxwidget extracted folder in extern/
mkdir build-cmake
cd build-cmake
cmake .. -DwxBUILD_SHARED=OFF -DwxBUILD_GUI=ON # find dependecies
make -j$(nproc) # build dependecies
sudo make install
```
