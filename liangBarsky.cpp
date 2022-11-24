#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
int xy[4];

void LiangBarsky(float x1, float y1, float x2, float y2) {
  float p[5], q[5];  // left-1 right-2 bottom-3 top-4
  p[1] = x1 - x2, p[2] = x2 - x1, p[3] = y1 - y2, p[4] = y2 - y1;
  q[1] = x1 - xy[0], q[2] = xy[1] - x1, q[3] = y1 - xy[2], q[4] = xy[3] - y1;
  float u1 = 0, u2 = 1;
  for (int i = 1; i < 5; i++) {
    if (p[i] < 0) {
      float r = q[i] / p[i];
      u1 = max(r, u1);
    }
    if (p[i] > 0) {
      float r = q[i] / p[i];
      u2 = min(u2, r);
    }
  }
  if (u1 > u2) {
    cout << "Line is out of clipping window";
    return;
  }
  cout << u1 << " " << u2 << endl;
  float x11 = x1 + u1 * (x2 - x1);
  float x12 = x1 + u2 * (x2 - x1);
  float y11 = y1 + u1 * (y2 - y1);
  float y12 = y1 + u2 * (y2 - y1);
  cout << "\nClipped Line is: (" << x11 << "," << y11 << ") , (" << x12 << "," << y12 << ")\n\n";
  setcolor(4);
  setlinestyle(0, 0, 6);
  line(x11, y11, x12, y12);
}

int main() {
  initwindow(800, 800);
  cout << "Enter xmin xmax ymin ymax" << endl;
  cin >> xy[0] >> xy[1] >> xy[2] >> xy[3];
  rectangle(xy[0], xy[2], xy[1], xy[3]);
  cout << "Enter Line Coordinates" << endl;
  float x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  setcolor(1);
  setlinestyle(0, 0, 4);
  line(x1, y1, x2, y2);
  LiangBarsky(x1, y1, x2, y2);
  getch();
  return 0;
}
