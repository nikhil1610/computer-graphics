#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
int main() {
  int t;
  initwindow(800, 800);
  double xmin, xmax, ymin, ymax;
  cout << "Enter xmin xmax ymin ymax\n";
  cin >> xmin >> xmax >> ymin >> ymax;
  rectangle(xmin, ymin, xmax, ymax);
  cout << "No of lines:";
  cin >> t;
  while (t--) {
    double x1, y1, x2, y2;
    cout << "Enter x1,y1 x2,y2\n";
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);
    double slope = (y2 - y1) / (x2 - x1);
    int arr1[4] = {0}, arr2[4] = {0};  //TBRL
    if (x1 > xmax) arr1[2] = 1;  // Right
    if (x1 < xmin) arr1[3] = 1;  // Left
    if (y1 > ymax) arr1[0] = 1;  // Top
    if (y1 < ymin) arr1[1] = 1;  // Bottom
    if (x2 > xmax) arr2[2] = 1;
    if (x2 < xmin) arr2[3] = 1;
    if (y2 > ymax) arr2[0] = 1;
    if (y2 < ymin) arr2[1] = 1;
    cout << "Region codes are\n";
    cout << "For x1,y1\n";
    for (int i = 0; i < 4; i++)
      cout << arr1[i];
    cout << "\nFor x2,y2\n";
    for (int i = 0; i < 4; i++)
      cout << arr2[i];
    int flag = 1;
    for (int i = 0; i < 4; i++) {
      if ((arr1[i] & arr2[i]) == 1) {
        cout << "\nClipping not possible\n";
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << endl;
      if (arr1[2]) {
        y1 += slope * (xmax - x1);
        x1 = xmax;
      }
      if (arr1[3]) {
        y1 += slope * (xmin - x1);
        x1 = xmin;
      }
      if (arr1[0]) {
        x1 += (ymax - y1) / slope;
        y1 = ymax;
      }
      if (arr1[1]) {
        x1 += (ymin - y1) / slope;
        y1 = ymin;
      }
      if (arr2[2]) {
        y2 += slope * (xmax - x2);
        x2 = xmax;
      }
      if (arr2[3]) {
        y2 += slope * (xmin - x2);
        x2 = xmin;
      }
      if (arr2[0]) {
        x2 += (ymax - y2) / slope;
        y2 = ymax;
      }
      if (arr2[1]) {
        x2 += (ymin - y2) / slope;
        y2 = ymin;
      }
    }
    cout << "Coordinates of clipped lines are:";
    cout << "(" << x1 << "," << y1 << ")";
    cout << "(" << x2 << "," << y2 << ")" << endl;
    setcolor(1);
    if (flag)
      line(x1, y1, x2, y2);
  }
  getch();
  closegraph();
}
