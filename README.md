
# **Fract'ol**

## **Description**

The `Fract'ol` project is a graphical program that displays various fractals, such as the Julia set, Mandelbrot set, and Tricorn, using the MiniLibX library. It allows users to explore fractals interactively with mouse and keyboard inputs, offering an introduction to complex numbers, fractal mathematics, and graphical rendering.

---

## **Features**

- **Supported Fractals:**
  - Julia Set
  - Mandelbrot Set
  - Tricorn Fractal
- **Interactive Controls:**
  - **Keyboard:** Zoom, pan, change colors, and switch Julia sets.
  - **Mouse:** Zoom into specific regions.
- **Customizable Colors:** Dynamic palettes for fractal visualization.

---

## **Dependencies**

The project uses the following libraries:
- **MiniLibX**: A lightweight graphics library for rendering.
- **X11 Libraries**: Required for window management (`-lX11`, `-lXext`).
- **Math Libraries**: For complex number calculations (`-lm`, `-lz`).

---

## **Makefile**

The `Makefile` simplifies compilation and provides the following targets:

### **Targets**

#### **`all`**
Compiles the program:
```bash
make all
```

#### **`clean`**
Removes all object files:
```bash
make clean
```

#### **`fclean`**
Cleans object files and the compiled binary:
```bash
make fclean
```

#### **`re`**
Recompiles the program after cleaning:
```bash
make re
```

---

## **Source Files**

1. **Core Functionality**
   - `main.c`: Entry point of the program.
   - `check_args.c`: Validates input arguments.
   - `init_img.c`, `init_params.c`: Initializes images and parameters.

2. **Utilities**
   - `utils.c`, `mlx_utils.c`: Utility functions for math and MiniLibX.

3. **Events**
   - `key_events.c`: Handles keyboard interactions.
   - `mouse_events.c`: Manages mouse inputs.

4. **Fractals**
   - `julia.c`, `julia_set.c`: Julia set rendering.
   - `mandelbrot.c`: Mandelbrot fractal rendering.
   - `tricorn.c`: Tricorn fractal rendering.

5. **Other**
   - `palette.c`: Dynamic color palettes for visualization.
   - `free_win.c`: Frees allocated resources.

---

## **Controls**

### **Mouse:**
- **Scroll Up/Down:** Zoom in/out.

### **Keyboard:**
- **General Controls:**
  - `Esc` / `Q`: Exit the program.
  - Arrow Keys: Pan the view (Left/Right/Up/Down).

- **Julia Set Variants:**
  - Press `1` to `9`: Switch between predefined Julia set parameters.

- **Color Palettes:**
  - `Z`: Use color palette 1.
  - `X`: Use color palette 2.
  - `C`: Use color palette 3.
  - `V`: Use color palette 4.
  - `B`: Use color palette 5.

---

## **Compilation**

### **Building the Project**
Run the following command to compile the project:
```bash
make
```

### **Running the Program**
After compilation, launch the program with:
```bash
./fractol <fractal_name>
```
Replace `<fractal_name>` with one of the supported fractal types (`julia`, `mandelbrot`, `tricorn`).

---

## **Acknowledgments**

The `Fract'ol` project is part of the 42 School curriculum, designed to introduce students to graphical programming, fractal mathematics, and user interactivity.

---
