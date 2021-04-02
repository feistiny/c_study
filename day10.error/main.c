#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern int errno;

int main() {
    FILE *pf;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL) {
        fprintf(stderr, "错误号: %d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误: %u\n", strerror(errno));
    } else {
        fclose(pf);
    }
    return EXIT_SUCCESS;
}