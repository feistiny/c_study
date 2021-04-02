#include <stdio.h>

void f() {
    printf("f");
}

void F() {
    printf("F");
}

#define F F

int main() {
    f();
    F();
}