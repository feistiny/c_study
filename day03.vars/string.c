#include "stdio.h"

int main() {
    char str[100] = "abcdefghijklmnopqrstuvwxyz";
    printf("%u\n", str);
    // char 是整数类型，0是数值
    str[10] = 0;
    // char 还可以赋值字符类型
    // str[10] = '\0';
    printf("%u\n", str);
    return 0;
}
