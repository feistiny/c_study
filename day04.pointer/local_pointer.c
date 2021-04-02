#include "stdio.h"
#include "string.h"
int* f(int a , int b)
{
    int c = 0;
    c = a + b;
    int *d = &c;
    printf("%p\n",&c);
    return d;
}

// 函数栈上的局部指针是会被重复利用的
int main(void)
{
    int *p = f(4, 5);
    printf("%p\n",p);
    printf("%d\n",*p);
    return 0;
}
