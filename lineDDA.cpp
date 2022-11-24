#include<iostream>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
using namespace std;

void DDA(int X0, int Y0, int X1, int Y1) {
  // calculate dx & dy to get the slope
  int dx = X1 - X0;
  int dy = Y1 - Y0;

  // calculate steps required for generating pixels
  int steps = max(abs(dx),abs(dy));

  // calculate increment in x & y for each steps
  float Xinc = dx / (float) steps; //if steps = dx, then this would be 1, else the fraction part
  float Yinc = dy / (float) steps; //same for this,

  // Put pixel for each step
  float X = X0;
  float Y = Y0;
  for (int i = 0; i <= steps; i++) {
    putpixel(X, Y, WHITE); // put pixel at (X,Y)
    X += Xinc; // increment in x at each step
    Y += Yinc; // increment in y at each step
    delay(10);
  }
}

main() {
  initwindow(800, 800);
  cout << " Enter the X1, Y1, X2, Y2 : \t";
  while (1) { //drawing multiple lines until starting and end point is same
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
      break;
    DDA(x1, y1, x2, y2);
  }
  getch();
}
