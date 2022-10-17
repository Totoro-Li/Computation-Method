//
// Created by Totoro on 2022/10/4.
//
#ifndef ComputationMethod_COMMON_H
#define ComputationMethod_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define SDK_EXTERN __declspec(dllexport)
#else
#define SDK_EXTERN
#endif // _WIN32

//CFFI_DEF_START
typedef double (*func_d)(double); //Function to set from external
typedef double (*func_dd)(double, double); //Function to set from external
SDK_EXTERN double fixed_point_iteration(double x0, double N, func_d f);

SDK_EXTERN double gauss_seidel_iteration(int n, double **a, double *b, double *x, func_d f);

SDK_EXTERN double runge_kutta(double x0, double y0, double h, double x, func_dd f);

SDK_EXTERN double* lagrange(double** xy, int m, int n, double x);
SDK_EXTERN void set_functions(func_d f);
//CFFI_DEF_END

#ifdef __cplusplus
}
#endif // __cplusplus
#endif //ComputationMethod_COMMON_H
