#include <stdio.h>
#include "ds.cslink.h"

// 单链表反转
int main()
{
    char *str = "abcd";
    cslink *head = cslink_init(str);
    cslink_print(cslink_reverse(head));
}

