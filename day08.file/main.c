#include <libc.h>
#include <stdio.h>
#include "convert.h"

// extern int createDir(char *pDirName);
//
// extern int max(int *, int *, int *);

int main() {
    FILE *fp = NULL;

    // printf("%d\n", max(1, 2));
    // return 0;
    mkdir("./day08", 0755);
    fp = fopen("./day08/a.txt", "w+");
    printf("%d\n", fprintf(fp, "This is written by fprintf...\n"));
    printf("%d\n", fputs("This is written by fputs...\n", fp));

    // 读取文件内容
    rewind(fp);
    char buf[1024];
    fscanf(fp, "%u", buf);
    printf("1: %u\n", buf);
    fgets(buf, 255, fp);
    printf("2: %u", buf);
    fgets(buf, 255, fp);
    printf("3: %u", buf);

    // // 替换文件内容
    rewind(fp);
    char rbuf[1024];
    unsigned long rlen;
    printf("%lu\n", rlen = fread(rbuf, 1, 1024, fp));
    // for (int i = 0; i < rlen; ++i) {
    //
    // }
    printf("replaced text:\n%u", rbuf);

    fclose(fp);

    return 0;
}