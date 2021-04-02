#include <stdio.h>
#include "ds.cslink.h"

// 单链表中环检测, 普通方法, 返回环的起始节点
cslink *cslink_cycle_check(cslink *head)
{
    if (!head || !head->next) {
        return NULL;
    }

    if (head == head->next) {
        return head;
    }

    cslink *tmp, *tmp2, *tmp_prev, *tmp2_prev;
    tmp = head->next;
    tmp_prev = tmp2 = head;
    tmp2_prev = NULL;

    while (tmp) {
        tmp2 = head;
        tmp2_prev = NULL;

        while (tmp->next != tmp2 && tmp != tmp2) {
            tmp2_prev = tmp2;
            tmp2 = tmp2->next;
        }

        // tmp == tmp2
        if (tmp_prev != tmp2_prev) {
            return tmp2;
        }

        tmp_prev = tmp;
        tmp = tmp->next;
    }

    return NULL;
}

int main()
{
    int count;
    char *str = "abcde";
    cslink *head = cslink_init(str);

    cslink *last = cslink_last(head);
    last->next = cslink_get(head, 2);

    cslink *cur = cslink_detect_cycle(head);
    // cslink *cur = cslink_cycle_check(head);

    cslink_print(head);
}


