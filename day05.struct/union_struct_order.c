#include <stdio.h>

union {
    struct {
        short s1; // 2 bytes, 16 bits
        short s2; // 2 bytes, 16 bits
    }; // struct 可以匿名, 直接 u.s1 可以访问到内部的元素
    int i; // 4 bytes, 32 bits
} u;

int main() {
    u.i = 3; // s1 s2 分别是多少

    // 证明 s1 在低位, s2 在高位
    printf("s1: %d\n", u.s1);
    printf("s1: %d\n", u.s2);
}
