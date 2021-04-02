#include <stdio.h>
#include "ds.cslink.h"

// 单链表反转
int main()
{
    cslink *head = cslink_init("abcd");
    cslink_print(cslink_reverse(head));
}

