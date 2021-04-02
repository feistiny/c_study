#include <stdio.h>
#include <libc.h>

static inline char *
strstr2(const unsigned char *hs, const unsigned char *ne)
{
    uint32_t h1 = (ne[0] << 16) | ne[1];
    uint32_t h2 = 0;
    for (int c = hs[0]; h1 != h2 && c != 0; c = *++hs)
        h2 = (h2 << 16) | c;
    return h1 == h2 ? (char *)hs - 2 : NULL;
}

// glibc 里 needle 长度是 2 时的优化
int main()
{
    const unsigned char *hs;
    const unsigned char *ne;
    char *p;
    hs = (const unsigned char *)"abcd";
    ne = (const unsigned char *)"ab";

    p = strstr2(hs, ne);
    printf("%c\n", p);
}

