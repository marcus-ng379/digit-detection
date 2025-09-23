# Digit Detection

A C++ application for recognizing handwritten digits with a neural network using wxWidgets for GUI rendering.

## Requirements
- Ubuntu 24.04 or later
- CMake 3.16 or later
- C++17 compiler
  
<details>
<summary><strong>Install wxWidgets Locally (OPTIONAL)</strong></summary>
Method 1: [wxWidgets Installation Guide](https://github.com/marcus-ng379/digit-detection/blob/main/wxWidgetsInstallation.md)
Method 2: Install directly:
  
    sudo apt install libwxgtk3.2-dev
  
</details>

## Installation
1. Make sure you've updated your system
```bash
sudo apt update
sudo apt upgrade
```

2. Install dependecies
```bash
sudo apt install cmake # Install CMakeLists
sudo apt install build-essential # Installs Make, G++, GCC
sudo apt install libgtk-3-dev # CMake Dependecy 
```

3. Clone the project using
```bash
git clone https://github.com/marcus-ng379/digit-detection.git
cd digit-detection
```

4. Build the project from one of the options:
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


5. Run the program inside the *build*
```bash
./Digit_Detection
```
