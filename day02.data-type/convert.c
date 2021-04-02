#include <stdio.h>

int main() {
    /*
     * 类型转换
     * 源自 PHP 源码的 _zend_hash_init 的 uninitialized_bucket
     */

    // 没有截断
    printf("%d\n", -((unsigned int)-2));
    printf("%u\n", -((unsigned int)-2));

    // 没有截断, 最后打印的时候有补位
    signed char sc_to_int = -2;
    printf("%d\n", -((unsigned char)sc_to_int));
    printf("%u\n", -((unsigned char)sc_to_int));

    // 负号(当做类型转换符), 无论作用到正数还是负数上, 位运算规则都是:
    // 1. 符号位反转
    // 2. 数字位取反
    // 3. 数字位+1, 如果溢出了, 不要影响符号位

    printf("\n试验: 测试截断\n");
    printf("-1 => unsigned char : %u\n", (unsigned char)-1);
    printf("-127 => unsigned char : %u\n", (unsigned char)-127);
    printf("-128 => unsigned char : %u\n", (unsigned char)-128);
    printf("-129 => unsigned char : %u\n", (unsigned char)-129);
    printf("-255 => unsigned char : %u\n", (unsigned char)-255);
    // 结论: 阶段就是把高位的符号位和数字位直接丢弃, 注意负数是在补码上截断的

    printf("\n试验: 测试不截断的类型转换\n");
    signed char sc = -1;
    printf("-1 => unsigned int : %x\n", (unsigned int)sc);
    // 结论: 高位补 1

    printf("\n试验: 用截断来判断类型转换操作的先后顺序\n");
    printf("-129 => unsigned char => - : %d\n", -((unsigned char) -129));
    unsigned char uc = -129; // 直接被截断成 127
    // printf("127 => int : %d\n", uc);
    printf("127 => - => int : %d\n", -uc);
    // printf("127 => - => unsigned int : %u\n", -uc);
    // 结论: 连续操作和分开操作的最终结果是一样的, 连续的类型转换操作的顺序都是从右到左

    return 0;
}
