
#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "Tests.hpp"

#include "SquareSolver.hpp"

const int Eq_NUM = 13;
const int coeff_NUM = 4;
double SQR_coeff[Eq_NUM][coeff_NUM] =
    {
      {4,  5, -1, 2},    //1
      {-9, -1, -1, 0},   //2
      {2, -1, 3.5, 0},   //3
      {1,  3, -5, 2},    //4
      {8,  10, 7, 0},    //5
      {1,  2, 1, 1},     //6
      {4,  4, 1, 1},     //7
      {1,  4, 8, 0},     //8
      {0.5,0.1, 0.1, 0}, //9
      {1, -2, 15, 0},    //10
      {0, 0, 0, INF},    //11
      {0, 1, 0, 1},      //12
      {0, 0, 54, 0}      //13
    };

//void TEST(double a, double b, double c, int korni);

int ALL_TESTS(void)
{

    for (int i = 0; i < Eq_NUM; i++)
    {
      double a = 0, b = 0, c = 0;

      a = SQR_coeff[i][0];
      b = SQR_coeff[i][1];
      c = SQR_coeff[i][2];
      int korni = SQR_coeff[i][3];
      printf("%d ", i + 1);
      TEST(a, b, c, korni);
     }
  return 0;
}



void TEST(double a, double b, double c, int korni)
{

    double x1 = 0, x2 = 0;
    int num = solve_sqr(a, b, c, &x1, &x2);
    double check1 = a*x1*x1 + b*x1 + c;
    double check2 = a*x2*x2 + b*x2 + c;
    //ASSERT(num == korni);
    if (num == korni) {
        switch (num) {
            case 0:
                printf("TEST OK\n");
                break;
            case 1:
                if (is_zero(check1)) {
                  printf("TEST OK\n");
                }
                else {
                  printf("FAILED\n");
                }
                break;
            case 2:
                if (is_zero(check1) && is_zero(check2)) {
                  printf("TEST OK\n");
                }
                else {
                  printf("FAILED\n");
                }
                break;
            case INF:
                printf("TEST OK\n");
                break;
           }
    }
    else
        printf("FAILED: num != korni\n");
}



