#include<graphics.h>
#include<iostream>
using namespace std;

void putpixels(int x, int y, int Xcenter, int Ycenter) {
  putpixel(x + Xcenter, y + Ycenter, 1);    //BLUE - 1
  putpixel(-x + Xcenter, y + Ycenter, 2);   //GREEN - 8
  putpixel(x + Xcenter, -y + Ycenter, 3);   //CYAN - 4
  putpixel(-x + Xcenter, -y + Ycenter, 4);  //RED - 5
  putpixel(y + Xcenter, x + Ycenter, 5);    //MAGENTA - 2
  putpixel(-y + Xcenter, x + Ycenter, 6);   //BROWN - 7
  putpixel(y + Xcenter, -x + Ycenter, 7);   //LIGHTGRAY - 3
  putpixel(-y + Xcenter, -x + Ycenter, 8);  //DARKGRAY - 6
}

void MidpointCircleAlgo(int Xcenter = 400, int Ycenter = 400, int radius = 100, int i = 1) {
  int x = 0, y = radius;
  int d = 1 - radius;

  while (x <= y) {
    putpixels(x, y, Xcenter, Ycenter);
    x++;
    if (d < 0) {
      d += 2 * (x + 1) + 1;
    } else {
      y--;
      d += 2 * (x - y) + 1;
    }
  }
}
int main() {
  initwindow(1500, 800);
  int x, y, r;
  cout << " \n Enter co-ordinates (x,y) of center :\t";
  cin >> x >> y;
  cout << "\n Enter radius : \t";
  cin >> r;

  MidpointCircleAlgo(x, y, r);

  getch();
}
