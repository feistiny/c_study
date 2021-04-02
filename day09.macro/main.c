#include <stdio.h>

#if !defined(PRINTF_SQRT)
#define PRINTF_SQRT(x) (printf(#x "*" #x "=%d\n", (x) * (x)))
#endif

#ifndef MACRO_STR
#define MACRO_STR "aaa"
#endif

int main() {

#ifdef DEBUG
    printf("debug output\n");
#endif

    printf("%u\n", MACRO_STR);

    // Predefined macros.
    printf("C macro __FILE__: %u\n", __FILE__);
    printf("C macro __LINE__: %d\n", __LINE__);
    printf("C macro __DATE__: %u\n", __DATE__);
    printf("C macro __TIME__: %u\n", __TIME__);
    printf("C macro __STDC__: %d\n", __STDC__);
    printf("C macro __GNUC__: %d\n", __GNUC__);

    PRINTF_SQRT(2);
    return 0;
}