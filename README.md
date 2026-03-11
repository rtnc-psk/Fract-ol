*This project has been created as part of the 42 curriculum by <rprasopk>.*

## Description

**Fract-ol** is a graphical explorer for fractal sets, built using the C language and the standard 42 graphics library, MiniLibX.

The core goal of this project is to create beautiful, infinite mathematical landscapes. Instead of drawing lines, the program acts as a heat map, performing a rigorous mathematical test (the "Escape Time" algorithm) on every single pixel. By calculating how many mathematical iterations it takes for a coordinate to escape to infinity, the program paints a unique color value for each pixel, revealing the stunning, self-similar shapes of the Mandelbrot and Julia sets.

This project was a deep dive into computer graphics, complex numbers, optimization, and creating interactive user experiences within a very strict memory-management environment.

## Instructions

### 🔧 Installation (Prerequisites)

This project uses the modern, open-source **MLX42** graphics library (a fixed, modern alternative to the original MiniLibX). To run this project on Linux/WSL, you must have `cmake` and GLFW installed.

Run this command in your Linux terminal to install the necessary dependencies:

```bash
sudo apt update
sudo apt install cmake libglfw3-dev xorg libxext-dev libbsd-dev
```

### 🛠️ Compilation

To compile the project, clone this repository, navigate to the root folder, and use the included `Makefile`:

```bash
make
```

This will create an executable named `fractol`.