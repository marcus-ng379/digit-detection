# Digit Detection

A C++ application for recognizing handwritten digits with neural network using wxWidgets for GUI rendering.

# Requirements
Make sure you have Ubuntu Version 24.04 or above!

## Installation

To install wxWidgets on Ubuntu:   
1. Download the Source for Linux under *Latest Stable Release: 3.2.8* on the web https://wxwidgets.org/downloads/
  
2. Update your system apt:
```bash
sudo apt update
sudo apt upgrade
```

3. Build all dependecies and Tools required for using CMake and C++.
```bash
sudo apt install build-essential libgtk-3-dev pkg-config bzip2
``` 

4. Extract and Build wxWidgets Locally
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
