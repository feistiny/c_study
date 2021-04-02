#include <stdio.h>
#include "ds.cslink.h"

// 删除链表倒数第 n 个结点
int main()
{
    cslink *head = cslink_init("abcdcba");

    cslink_print(head);
    printf("\n");
    cslink_delete(head, -1);
    cslink_print(head);
    printf("\n");
    cslink_delete(head, -1);
    cslink_print(head);
    printf("\n");
    cslink_delete(head, -2);
    cslink_print(head);
}


