#include<iostream>
#include <graphics.h>
using namespace std;
  
const int MAX_POINTS = 20;
  
// Returns x-value of point of intersection of two
// lines
int x_intersect(int x1, int y1, int x2, int y2,
                int x3, int y3, int x4, int y4)
{
    int num = (x1*y2 - y1*x2) * (x3-x4) -
              (x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    return num/den;
}
  
// Returns y-value of point of intersection of
// two lines
int y_intersect(int x1, int y1, int x2, int y2,
                int x3, int y3, int x4, int y4)
{
    int num = (x1*y2 - y1*x2) * (y3-y4) -
              (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    return num/den;
}
  
// This functions clips all the edges w.r.t one clip
// edge of clipping area
void clip(int poly_points[][2], int &poly_size,
          int x1, int y1, int x2, int y2)
{
    int new_points[MAX_POINTS][2], new_poly_size = 0;
  
    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = poly_points[i][0], iy = poly_points[i][1];
        int kx = poly_points[k][0], ky = poly_points[k][1];
  
        // Calculating position of first point
        // w.r.t. clipper line
        int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);
  
        // Calculating position of second point
        // w.r.t. clipper line
        int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);
  
        // Case 1 : When both points are inside
        if (i_pos < 0  && k_pos < 0)
        {
            //Only second point is added
            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }
  
        // Case 2: When only first point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            // Point of intersection with edge
            // and the second point is added
            new_points[new_poly_size][0] = x_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;
  
            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }
  
        // Case 3: When only second point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            //Only point of intersection with edge is added
            new_points[new_poly_size][0] = x_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;
        }
  
        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }
  
    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    for (int i = 0; i < poly_size; i++)
    {
        poly_points[i][0] = new_points[i][0];
        poly_points[i][1] = new_points[i][1];
    }
}
  
// Implements Sutherland–Hodgman algorithm
void suthHodgClip(int poly_points[][2], int poly_size,
                  int clipper_points[][2], int clipper_size)
{
    //i and k are two consecutive indexes
    for (int i=0; i<clipper_size; i++)
    {
        int k = (i+1) % clipper_size;
  
        // We pass the current array of vertices, it's size
        // and the end points of the selected clipper line
        clip(poly_points, poly_size, clipper_points[i][0],
             clipper_points[i][1], clipper_points[k][0],
             clipper_points[k][1]);
    }
  
    // Printing vertices of clipped polygon
    cout << "\nClipped Polygon : " << endl;
    for (int i=0; i < poly_size; i++)
        cout << '(' << poly_points[i][0] <<
                ", " << poly_points[i][1] << ") ";
    cout << endl << endl;

    // Drawing Clipped Polygon
    int poly_clipped[50];
    for (int q = 0; q < poly_size; q++)
    {
        for (int t = 0; t < 2; t++)
        {
            poly_clipped[q * 2 + t] = poly_points[q][t];
        }
    }
    setcolor(BLUE);
    poly_clipped[2 * poly_size] = poly_clipped[0];
    poly_clipped[2 * poly_size + 1] = poly_clipped[1];
    drawpoly(poly_size + 1, poly_clipped);

    getch();
}
  
//Driver code
int main()
{
    int gd = DETECT, gm, errorcode;
    initgraph(&gd, &gm, NULL);

    // Defining polygon vertices in clockwise order
    int poly_size = 3;
    int poly_points[20][2] = {{100,150}, {200,250},
                              {300,100}};
  
    // Defining clipper polygon vertices in clockwise order
    // 1st Example with square clipper
    int clipper_size = 4;
    int clipper_points[][2] = {{100,100}, {100,200},
                              {200,200}, {200,100} };
    setcolor(RED);
    rectangle(100, 100, 200, 200);

    setcolor(YELLOW);
    int poly[50];
    for (int q = 0; q < poly_size; q++)
    {
        for (int t = 0; t < 2; t++)
        {
            poly[q * 2 + t] = poly_points[q][t];
        }
    }
    poly[2 * poly_size] = poly[0];
    poly[2 * poly_size + 1] = poly[1];
    drawpoly(poly_size + 1, poly);
  
    //Calling the clipping function
    suthHodgClip(poly_points, poly_size, clipper_points,
                 clipper_size);

    getch();
  
    return 0;
}

