#include <stdio.h>
//#define TX_COMPILING
#include <TXLib.h>
#include <math.h>
#include "SquareSolver.hpp"

int solve_sqr(double k1, double k2, double k3, double *x1, double *x2)
{
    int korni = 0;
    double D = k2*k2 - 4*k1*k3;

    if (is_zero(k1))
    {
        korni = solve_lin(k2, k3, x1);
    }
    else
    {
        if (D > 0)
        {
            *x1 = (-k2 + sqrt(D))/2/k1;
            *x2 = (-k2 - sqrt(D))/2/k1;
            korni = 2;
        }
        else if (is_zero(D))
        {
            *x1 = -k2/2/k1;
            korni = 1;
        }
    else {
        korni = 0;
        }
    }

    return korni;
}

int solve_lin(double k2, double k3, double *x1)
{
    if (is_zero(k2) && !is_zero(k3))
        return 0;
    else if(is_zero(k2) && is_zero(k3))
        return INF;
    else
    {
        *x1 = -k3 / k2;
        return 1;
    }
}

void sqr_out(int num)
{
    switch (num) {
        case 0:
            printf("????????? ?? ????? ???????.\n");
            break;
        case 1:
            printf("x = %lf", x1);
            break;
        case 2:
            printf("x1 = %lf\nx2 = %lf", x1, x2);
            break;
        case INF:
            printf("????????? ????? ?????????? ????? ???????.\n");
            break;
        }
}

int is_zero(double x)
{
    const double SMALL = 1e-8;
    return fabs(x) < SMALL;
}

