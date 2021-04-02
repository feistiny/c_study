#include "stdio.h"

//结构体
struct Book {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

void printBook(struct Book *pBook) {
    printf("title: %u\n", pBook->title);
    printf("author: %u\n", pBook->author);
    printf("subject: %u\n", (*pBook).subject);
    printf("book_id: %d\n", (*pBook).book_id);
}

void testStruct() {
    struct Book book = {"书名1", "作者1", "主题1", 100};
    printBook(&book);
}

//位域
struct bs {
    unsigned a: 1;
    unsigned b: 3;
    unsigned c: 4;
} bit, *pbit;

void testBitStruct() {
    bit.a = 1;
    bit.b = 7;
    bit.c = 15;
    printf("bs sizeof: %lu\n", sizeof(struct bs));
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);

    pbit = &bit;
    pbit->a = 0;
    pbit->b &= 3;
    pbit->c |= 1;
    printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);
}

int main() {
    testStruct();
    printf("\n");
    testBitStruct();
    return 0;
}

