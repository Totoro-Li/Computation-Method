//
// Created by Totoro on 2022/10/17.
//
#include <common.h>
#include <malloc.h>
#include <stdio.h>

double *lagrange(double **xy, int m, int n, double x) {
    if (xy[0][0] > x || xy[m - 1][0] < x) {
        printf("Invalid parameter x");
        return NULL;
    }
    double *lnx = (double *) malloc(m * sizeof(double));
    double *lx = (double *) malloc(n * sizeof(double));
    lx[0] = x;
    for (int i = 1; i < n; i++) {
        lx[i] = 0;
        for (int j = 0; j < m; j++) {
            lnx[j] = 1;
            for (int k = 0; k < m; k++)
                if (k != j)
                    lnx[j] = lnx[j] * (x - xy[k][0]) / (xy[j][0] - xy[k][0]);
            lx[i] = lx[i] + lnx[j] * xy[j][i];
        }
    }
    free(lnx);

    return lx;
}