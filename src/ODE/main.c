//
// Created by Totoro on 2022/10/5.
//
#include<common.h>

double runge_kutta(double x0, double y0, double h, double x, func_dd f) {
    int n = (int) ((x - x0) / h);
    double k1, k2, k3, k4, k5;
    double y = y0;
    for (int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 = x0 + h;
    }
    return y;
}


