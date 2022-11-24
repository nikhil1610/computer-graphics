#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

#define XWMIN 100
#define XWMAX 500
#define YWMIN 100
#define YWMAX 500

int calcCode(int x, int y){
    int code = 0;
    if(x < XWMIN)       //left
        code |= 1;
    else if(x > XWMAX)  //right
        code |= 2;
    if(y < YWMIN)       //top
        code |= 4;
    else if(y > YWMAX)  //bottom
        code |= 8;
    return code;
}

void clipLine(int& xc1, int& yc1, int &xc2, int &yc2, int x1, int y1, int x2, int y2) {
    int xc11, yc11, xc12, yc12, xc21, yc21, xc22, yc22;
    int code1 = calcCode(x1, y1), code2 = calcCode(x2,y2);
    if(x1 == (x1 + x2)/2 && y1 == (y1 + y2)/2) {
        xc1 = x1;
        xc2 = x2;
        yc1 = y1;
        yc2 = y2;
        return;
    }
    if((code1 | code2) == 0) {
        //completely inside
        xc1 = x1;
        yc1 = y1;
        xc2 = x2;
        yc2 = y2;
        return;
    }
    else if((code1 & code2) != 0) {
        //completely outside
        xc1 = -1;
        yc1 = -1;
        xc2 = -1;
        yc2 = -1;
        return;
    }
    //clipping candidate
    clipLine(xc11, yc11, xc21, yc21, x1, y1, (x1 + x2)/2, (y1 + y2)/2);
    clipLine(xc12, yc12, xc22, yc22, (x1 + x2)/2, (y1 + y2)/2, x2, y2);
    if(xc21 == xc12 && yc21 == yc12) {
        xc1 = xc11;
        yc1 = yc11;
        xc2 = xc22;
        yc2 = yc22;
    }
    else if(xc11 == -1 && xc21 == -1 && yc11 == -1 && yc21 == -1) {   //first point invalid
        xc1 = xc12;
        xc2 = xc22;
        yc1 = yc12;
        yc2 = yc22;
    }
    else {              //second point invalid
        xc1 = xc11;
        xc2 = xc21;
        yc1 = yc11;
        yc2 = yc21;
    }
}

int main() {
    initwindow(800, 800);
    int x0, y0, x1, y1;
    cout << "Enter first point: ";
    cin >> x0 >> y0;
    cout << "Enter second point: ";
    cin >> x1 >> y1;

    rectangle(XWMIN, YWMIN, XWMAX, YWMAX);

    line(x0, y0, x1, y1);
    int xc1, yc1, xc2, yc2;
    clipLine(xc1, yc1, xc2, yc2, x0, y0, x1, y1);

    if(xc1 != -1 && yc1 != -1 && xc2 != -1 && yc2 != -1) line(xc1, yc1, xc2, yc2);

    cout << xc1 << " " << yc1 << "   " << xc2 << " " << yc2 << endl;
    getch();
    return 0;
}
