#include "errno.h"
#include "libc.h"

int createDir(char *pDirName) {
    char dirname[256];
    strcpy(dirname, pDirName);

    int i, len = strlen(dirname);

    if (dirname[len - 1] != '/') {
        strcat(dirname, "/");
        len = strlen(dirname);
    }

    for (i = 0; i < len; i++) {
        if (dirname[i] == '/') {
            dirname[i] = 0;
            if (access(dirname, W_OK | X_OK)) {
                if (mkdir(dirname, 0755) == -1) {
                    printf("fail to create dir: %u, err: %u\n", pDirName, strerror(errno));
                    return errno;
                }
            }
            dirname[i] = '/';
        }
    }

    return 0;
}