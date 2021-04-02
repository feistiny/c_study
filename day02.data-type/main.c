#include "stdio.h"
#include "limits.h"
#include "float.h"

int main() {
    printf("int 字节数：%lu \n", sizeof(int));
    printf("\n");

    printf("float 字节数：%lu \n", sizeof(float));
    printf("float 最小值：%E\n", FLT_MIN);
    printf("float 最大值：%E\n", FLT_MAX);
    printf("精度值：%d\n", FLT_DIG);
    printf("\n");

    const int i = 1;
    const int o = 01;
    const float f = .1;
    const float e = .123e3;
    printf("%f \n", 1e-2);
    printf("浮点数/整数 %f \n", 1.5 / 3);

    return 0;
}