*This project has been created as part of the 42 curriculum by rprasopk.*

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

### 🚀 Execution

To start the program, run the executable and specify which fractal set you wish to explore.

#### 1. Mandelbrot Set

```bash
./fractol mandelbrot
```

#### 2. Julia Set

The Julia set requires you to provide two floating-point constants (between -2.0 and 2.0) to determine its shape:

```bash
# Example 1: The "Rabbit" Julia
./fractol julia -0.123 0.745

# Example 2: The "Dendrite" Julia
./fractol julia 0.285 0.01

# Example 3: The "Galactic" Julia
./fractol julia -0.4 0.6
```
### 🕹️ Controls

| Input | Action |
| --- | --- |
| **Arrow Keys** | Move (shift) the camera position |
| **Mouse Wheel** | Zoom In / Zoom Out |
| **Spacebar** | Dynamically shift the color scheme |
| **Esc Key** | Cleanly exit and close the program |