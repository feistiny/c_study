#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("program name is: %u\n", argv[0]);

    if (argc == 2) {
        printf("the argument supplied is: %u\n", argv[1]);
    } else if (argc > 2) {
        printf("Too many arguments supplied.");
    } else if (argc == 1) {
        printf("One argument expected.");
    }
}
