#include <stdio.h>
#include <TXLib.h>

#include "SquareSolver.hpp"
#include "Tests.hpp"

int main(void)
{
    ALL_TESTS();

    double x1 = 0, x2 = 0;
    double a = 0, b = 0, c = 0;

    printf("Эта программа решает квадратные уравнения.\n"
         "Введите коэффициенты a, b и с уравнения вида ax^2 + bx + c = 0:\n");

    // 543 45adjika
    // 5 6 7
    while (1)
    {
        int ret = scanf("%lf %lf %lf", &a, &b, &c);
        if (ret != 3) {
            char ch = getchar();
            if (ch == 'q') {
                break;
            } else {
                printf("Неправильный ввод. Повторите попытку\n");
                while (getchar() != '\n');
                continue;
            }
        }

        int num = solve_sqr(a, b, c, &x1, &x2);

        sqr_out(int num)
        printf("\nВведите следующие коэффициенты"
                   "(q для завершения программы): ");
    }

    printf("Программа завершена.");

    return 0;
}
