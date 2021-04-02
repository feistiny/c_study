#include <string.h>
#include "stdio.h"

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    // 指针大小, 跟平台有关
    void *tmp;
    printf("sizeof pointer: %lu\n", sizeof(tmp));

    // 函数指针
    int (*p)(int, int) = max;
    int a = 1, b = 2, c = 3, d;
    printf("请输入三个数字：");
    // scanf("%d %d %d", &a, &b, &c);
    d = p(p(a, b), c);
    printf("最大的数字是 %d\n", d);

    // 指针转换
    unsigned char ca[100] = "abc";
    printf("循环原指针: ");
    for (int i = 0; i < strlen((char *)ca); ++i) {
        printf("%c", ca[i]);
    }
    printf("\n");

    printf("sizeof int: %lu\n", sizeof(int));
    unsigned int *ia;
    // 小转大
    ia = (unsigned int *)ca;
    // 大转小
    unsigned char *ca2 = (unsigned char *)ia;

    printf("循环转换后的指针: ");
    for (int i = 0; i < strlen((char *)ca); ++i) {
        printf("%c", ca2[i]);
    }
    printf("\n");
    printf("ca pointer: %p\n", ca);
    printf("ia pointer: %p\n", ia);
    // printf("sizeof int*: %d\n", sizeof(ia));
    printf("ia: %x\n", *ia);
    printf("ia[0]: %x\n", ia[0]);
    printf("ia[1]: %x\n", ia[1]);

    return 0;
}