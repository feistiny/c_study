#include <stdio.h>

struct {
    unsigned char c1;
    unsigned char c2;
} st = {'a','b'};

int main() {
    printf("%c\n", (&st)->c2);

    return 0;
}
