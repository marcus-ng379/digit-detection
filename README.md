# Digit Detection

A C++ application for recognizing handwritten digits with a neural network using wxWidgets for GUI rendering.

## Requirements
- Ubuntu 24.04 or later
- CMake 3.16 or later
- C++17 compiler

If you have *sudo* permission, you can install wxWidgets locally via:

- [wxWidgets Installation Guide](https://github.com/marcus-ng379/digit-detection/blob/main/wxWidgetsInstallation.txt)
- Or directly:
  ```bash
  sudo apt install libwxgtk3.2-dev

## Installation
Make sure you've updated your system
```bash
sudo apt update
sudo apt upgrade
```

Install dependecies
```bash
sudo apt install cmake # Install CMakeLists
sudo apt install build-essential # Installs Make, G++, GCC
sudo apt install libgtk-3-dev # CMake Dependecy 
```

Clone the project using
```bash
git clone https://github.com/marcus-ng379/digit-detection.git
cd digit-detection
```

Build the project from one of the options:
<details>
<summary><strong>With wxWidgets installed locally</strong></summary>

If you already installed wxWidgets locally, you can simply compile the program with:

    mkdir build
    cd build
    cmake -DUSE_SYSTEM_WXWIDGETS=ON ..
    cmake --build .

</details>



<details>
<summary><strong>wxWidgets NOT installed locally</strong></summary>

Use the bundled submodule to build wxWidgets from source (note this may take a few minutes to fully build):

    git submodule update --init --recursive
    mkdir build
    cd build
    cmake -DUSE_SYSTEM_WXWIDGETS=OFF ..
    cmake --build .

</details>


Run the program inside *build*
```bash
./Digit_Detection
```
