#include "stdio.h"

void f(int **i, int *j)
{
    *i = j;
}

// 指针的指针
int main()
{
    int *i = NULL,
            j = 3;
    f(&i, &j);
    printf("%d\n", *i);
}
