#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void mid_Point_Ellipse(int rx, int ry, int xc, int yc) {
  float dx, dy, p1, p2, x = 0, y = ry;
  dx = 2 * ry * ry * x;
  dy = 2 * rx * rx * y;
  p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
  while (dx < dy) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    x++;
    if (p1 < 0) {
      dx += (2 * ry * ry);
      p1 += dx + (ry * ry);
    } else {
      y--;
      dx += (2 * ry * ry);
      dy -= (2 * rx * rx);
      p1 += dx - dy + (ry * ry);
    }
  }
  p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - rx * rx * ry * ry;
  while (y >= 0) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    y--;
    if (p2 > 0) {
      dy -= (2 * rx * rx);
      p2 += (rx * rx) - dy;
    } else {
      x++;
      dx += (2 * ry * ry);
      dy -= (2 * rx * rx);
      p2 += dx - dy + (rx * rx);
    }
  }
}

int main() {
  int rx, ry, xc, yc;
  cout << "Enter the center of ellipse: ";
  cin >> xc >> yc;
  cout << "Enter the length of major and minor axis: ";
  cin >> rx >> ry;
  initwindow(1000, 2000);
  mid_Point_Ellipse(rx, ry, xc, yc);
  getch();
  return 0;
}
