#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void mid_Point_Hyperbola(int a, int b, int xc, int yc) {
  float p1, p2, x = a, y = 0;
  p1 = b*b*(a+0.5)*(a+0.5)-a*a-a*a*b*b;

  while (y <= (b*b)*(x/(a*a))) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    if (p1 > 0)
      p1 = p1 - (a * a)*(2 * y + 3);
    else {
      x++;
      p1 = p1 - (a * a)*(2 * y + 3) + 2*(b * b) * x;
    }
    y++;
  }
  p2 = b*b*(x+1)*(x+1) - a*a*(y+0.5)*(y+0.5) - a*a*b*b;
  for(int i=0;i<100;i++) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    if (p2 > 0) {
      y++;
      p2 = p2 + (b*b)*(2*x+3) - 2*(a*a)*y;
    } else {
      p2 = p2 + (b*b)*(2*x+3);
    }
    x++;
  }
}

int main() {
  int rx, ry, xc, yc;
  cout << "Enter the center of hyperbola: ";
  cin >> xc >> yc;
  cout << "Enter the length of major and minor axis: ";
  cin >> rx >> ry;
  initwindow(1000, 2000);
  mid_Point_Hyperbola(rx, ry, xc, yc);
  getch();
  return 0;
}
