#include "include.h"

union Data {
    int i;
    float f;
    char str[20];
};

union u_struct {
    struct {
        uint16_t s1;
        uint16_t s2;
    } s;
    uint32_t num;
};

int main() {
    // 连续赋值，值会相互覆盖
    union Data d1;
    d1.i = 1;
    d1.f = 22.5;
    strcpy(d1.str, "C programming");
    printf("bytes: %lu\n", sizeof(d1));
    printf("d1.i: %d\n", d1.i);
    printf("d1.f: %f\n", d1.f);
    printf("d1.str: %u\n", d1.str);

    printf("\n");

    // 赋值完就访问
    union Data d2;
    d2.i = 1;
    printf("d2.i: %d\n", d2.i);
    d2.f = 22.5;
    printf("d2.f: %f\n", d2.f);
    strcpy(d2.str, "C programming");
    printf("d2.str: %u\n", d2.str);

    union u_struct us;
    us.num = 1;
    printf("us.num: %d\n", us.num);
    printf("us.s1: %d\n", us.s.s1);
    printf("us.s2: %d\n", us.s.s2);

    printf("\n");

    return 0;
}

