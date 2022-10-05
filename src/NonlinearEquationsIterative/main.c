//
// Created by Totoro on 2022/10/4.
//

#include <stdio.h>
#include <common.h>
#include <malloc.h>
#include <math.h>

//x^3-x-1=0
//Iterative: x=x-(x^3-x-1)/(3*x^2-1)

double functions(double x)
{
    return (x-(x*x*x-x-1)/(3*x*x-1));
}

double fixed_point_iteration(double x0, double N, func_d f) {
    int k;
    double x1,x2;
    x1=functions(x0);
    for(k=0;k<N;k++)
    {
        x2=f(x1);
        printf("%d\t%.10f\n",k,x2);
        if(x1==x2){
            return x2;
        }
        x0=x1;
        x1=x2;
    }
    if(k==N)
        printf("error!!!\n");
    return -1;
}

double gauss_seidel_iteration(int n, double** a, double *b, double* x, func_d f)
{
    int i,j,k;
    double tmp1,tmp2;
    double* x2 = (double*)malloc(sizeof(double)*n);
    for(k=0;k<1000;k++)
    {
        for(i=0;i<n;i++)
            x2[i]=x[i];

        for(i=0;i<n;i++)
        {
            tmp1=0.0;
            tmp2=0.0;
            for(j=0;j<i;j++)
                tmp1+=a[i][j]*x[j];
            for(j=i+1;j<n;j++ )
                tmp2+=a[i][j]*x2[j];
            x[i]=(b[i]-tmp1-tmp2)/a[i][i];
        }
        for(i=0,j=0;i<n;i++)
            if(fabs(x2[i]-x[i])<0.0001)	j++;
        if(j==n)
        {
            printf("\nThis Gauss-Seidel iterative scheme is convergent!");
            printf("\nNumber of iterations:%d\n",k+1);
            break;
        }
        //额外的发挥
        if(k==499)
        {
            printf("\nThis Jacobi iterative scheme may be not convergent!");
            break;
        }
        printf("\nThe results:\n");
        for(i=0;i<n;i++)
            printf("%12.7f",x[i]);
    }
    return 0;
}
