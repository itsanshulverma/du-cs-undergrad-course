# Computer Graphics (BHCS14)

***Written By Anshul Verma for University of Delhi***

### Setup `graphics.h`
- Follow this [link](https://www.geeksforgeeks.org/installing-mingw-tools-for-c-c-and-changing-environment-variable/) to download [MinGW](https://sourceforge.net/projects/mingw/) C++ Compiler(GCC).
- Download the three setup files, i.e. `graphics.h`, `winbgim.h` and `libbgi.a`.
- Copy the files `graphics.h` & `winbgim.h` to `C:\MinGW\include`.
- Copy the file `libbgi.a` to `C:\MinGW\lib`.

### To Run code
- To compile any cpp file with `<graphics.h`, use below:

  ```bash
  g++ **FILENAME**.cpp -o main -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
  ```
- To run, write `./main.exe`.

_You can also follow this [link](https://github.com/ish-u/computer-graphics), to setup and run code._

### Practical List
0. Write a program to implement DDA line drawing algorithm.
1. Write a program to implement Bresenham’s line drawing algorithm.
2. Write a program to implement mid-point circle drawing algorithm.
3. Write a program to clip a line using Cohen and Sutherland line clipping algorithm.
4. Write a program to clip a polygon using Sutherland Hodgeman algorithm.
5. ~~Write a program to fill a polygon using Scan line fill algorithm.~~
6. Write a program to apply various 2D transformations on a 2D object (use homogenous Coordinates).
7. Write a program to apply various 3D transformations on a 3D object and then apply parallel and perspective projection on it.
8. Write a program to draw Hermite /Bezier curve.
