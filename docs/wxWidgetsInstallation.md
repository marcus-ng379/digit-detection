# wxWidget Installation Guide

## Linux/macOS Installation Guide
Make sure you install all dependecies before continuing
```bash
sudo apt update
sudo apt upgrade
sudo apt install build-essential # G++, Gcc, Installation
sudo apt install bzip2 # .bz2 extraction
sudo apt install cmake # CMakeLists
sudo apt install libgtk-3-dev # CMake pkg
```
1. Navigate to [wxWidgets Downloads](https://wxwidgets.org/downloads/) and download the Source file for *Stable Build 3.2.8*
 
2. Find the file *wxWidgets-3.2.8.tar.bz2* on your machine and uncompress it using
```bash
tar -xjf wxWidgets-3.2.8.tar.bz2
cd wxWidgets-3.2.8
```

3. Build the wxWidget project using their respective CMakeLists
```bash
mkdir build-cmake
cd build-cmake
cmake .. -DwxBUILD_SHARED=OFF -DwxBUILD_GUI=ON
make -j$(nproc)
sudo make install # Installs system-wide
```

Don't forget to head back to the root of the folder *digit-detection* before continuing with the next steps!


