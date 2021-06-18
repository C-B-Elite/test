//
// Created by root on 2021/6/18.
//

#include "divideConquer.h"
int compare(int X[], int Y[], int XLow, int XHigh, int YLow, int YHigh) {
    if (XLow == XHigh) {
        return X[XLow];
    }
    else if (YLow == YHigh) {
        return Y[YLow];
    }

    int XMid, YMid;
    XMid = (XLow + XHigh) / 2;
    YMid = (YLow + YHigh) / 2;


    if (X[XMid] > Y[YMid]) {
        XHigh = XMid;
        YLow = YMid;
    }
    else if (X[XMid] < Y[YMid]) {
        XLow = XMid;
        YHigh = YMid;
    }
    else {
        return X[XMid];
    }

    compare(X, Y, XLow, XHigh, YLow, YHigh);
}