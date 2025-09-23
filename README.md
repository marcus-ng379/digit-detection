# Digit Detection

A C++ application for recognizing handwritten digits with neural network using wxWidgets for GUI rendering.

# Requirements
Make sure you have Ubuntu Version 24.04 or above!

## Installation

To install wxWidgets on Ubuntu:   
1. Upgrade your apt:
```bash
sudo apt update
sudo apt upgrade
```

2. Make sure you have all essentials installed.
Install all with
```bash
sudo apt install build-essential
sudo apt install libgtk-3-dev pkg-config
```

3. Navigate towards extern/wxWidgets-3.2.8 and build the wxWidget folder:
```bash
cmake .. -DwxBUILD_SHARED=OFF -DwxBUILD_GUI=ON
make -j$(nproc)
sudo make install
```
