#include<graphics.h>
#include<iostream>
using namespace std;

void plotPoints(int x, int y, int xCentre, int yCentre) {
  putpixel(x + xCentre, y + yCentre, 15);
  putpixel(y + xCentre, x + yCentre, 15);
  putpixel(y + xCentre, -x + yCentre, 15);
  putpixel(x + xCentre, -y + yCentre, 15);
  putpixel(-x + xCentre, -y + yCentre, 15);
  putpixel(-y + xCentre, -x + yCentre, 15);
  putpixel(-y + xCentre, x + yCentre, 15);
  putpixel(-x + xCentre, y + yCentre, 15);
}

void circleBresenham(int xC, int yC, int r) {
  int x = 0, y = r;
  int Dk = 3 - (2 * r);
  while (x <= y) {
    plotPoints(x, y, xC, yC);
    x++;
    if (Dk < 0)
      Dk = Dk + (4 * x) + 6;
    else {
      y--;
      Dk = Dk + 4 * (x - y) + 10;
    }
  }
}

int main() {
  int xC, yC, r;
  cout << "Enter center and radius: ";
  cin >> xC >> yC >> r;
  initwindow(800, 800);
  circleBresenham(xC, yC, r);
  getch();
}
