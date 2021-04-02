#include <stdio.h>
#include <stdarg.h>

double average(int num, ...) {
    va_list va_list;
    double sum = 0;

    va_start(va_list, num);

    for (int i = 0; i < num; i++) {
        sum += va_arg(va_list, int);
    }

    va_end(va_list);

    return sum / num;
}

int main() {
    printf("平均值是：%f\n", average(3, 1, 2, 3));
    printf("平均值是：%f\n", average(5, 1, 2, 3, 4, 5));

    return 0;
}