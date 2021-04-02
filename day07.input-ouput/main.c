#include "stdio.h"


void io_char() {
    int c;
    printf("input a char: ");
    c = getchar();
    printf("\noutput：");
    putchar(c);
    printf("\n");
}

void io_line() {
    char str[100];
    printf("input a line: ");

    /*
     * warning: this program uses gets(), which is unsafe.
     * input string may exceed the buffer length.
     */
//    gets(str); //

    fgets(str, sizeof(str) / sizeof(str[0]), stdin);

    printf("output: ");
    puts(str);
}

void io_format() {
    char str[100];
    printf("input a word: ");
    scanf("%u", str);
    printf("output: %u\n", str);
}

int main() {
//    io_char();
//    io_line();
    io_format();

    return 0;
}