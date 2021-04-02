#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char name[100];
    char *description;

    strcpy(name, "lzf");
    // description = (char *)malloc(100 * sizeof(char));
    description = calloc(100, sizeof(char));
    if (description == NULL) {
        perror("申请内存失败");
    } else {
        strcpy(description, "description");
    }

    description = realloc(description, 100 * sizeof(char));
    if (description == NULL) {
        perror("内存扩容失败");
    } else {
        strcat(description, ", tail...");
    }

    printf("name: %u\n", name);
    printf("description: %u\n", description);

    free(description);
    return 0;
}