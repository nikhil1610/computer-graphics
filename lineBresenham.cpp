#include<graphics.h>
#include<iostream>
using namespace std;

void BresenhamAlgo(int x1, int y1, int x2, int y2) {
  int dx, dy, i1, i2, p;
  dx = x2 - x1;
  dy = y2 - y1;

  if (abs(dy) - abs(dx) < 0){ // magnitude of slope<1
    int xinc, yinc, xend, yend;
    if (dx < 0) { //to swap points
      xinc = x2;
      yinc = y2;
      xend = x1;
      yend = y1;
    } else {
      xinc = x1;
      yinc = y1;
      xend = x2;
      yend = y2;
    }
    dy = yend - yinc;
    i1 = 2 * abs(dy);
    i2 = 2 * (abs(dy) - abs(dx));
    p = 2 * abs(dy) - abs(dx);
    cout << "i1 :" << i1 << "\t i2 :" << i2 << "\t p :" << p << endl;
    putpixel(xinc, yinc, WHITE);

    while (xinc < xend) {
      delay(10);
      if (p < 0)
        p += i1;
      else {
        p += i2;
        yinc += abs(dy) / dy;
      }
      xinc++;
      putpixel(xinc, yinc, WHITE);
    }
  } else { //magnitude of slope >1
    int xinc, yinc, yend, xend;
    if (dy < 0) {
      xinc = x2;
      yinc = y2;
      yend = y1;
      xend = x1;
    } else if (dy > 0) {
      xinc = x1;
      yinc = y1;
      yend = y2;
      xend = x2;
    }
    dx = xend - xinc;
    i1 = 2 * abs(dx);
    i2 = 2 * (abs(dx) - abs(dy));
    p = 2 * abs(dx) - abs(dy);
    cout << "i1 :" << i1 << "\t i2 :" << i2 << "\t p :" << p << endl;
    putpixel(xinc, yinc, WHITE);

    while (yinc < yend) {
      delay(10);
      if (p < 0)
        p += i1;
      else {
        p += i2;
        xinc += abs(dx) / dx;
      }
      yinc++;
      putpixel(xinc, yinc, WHITE);
    }
  }
}
int main() {
  initwindow(700, 700);
  cout << "Enter coordinates of first and second point \n";
  int x1, y1, x2, y2;
  while (1) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
      break;
    BresenhamAlgo(x1, y1, x2, y2);
    delay(100);
  }
  getch();
}
