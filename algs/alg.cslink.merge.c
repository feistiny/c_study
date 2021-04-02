#include <stdio.h>
#include "ds.cslink.h"

// 合并有序链表, in-palce模式, 破坏了原来的两个链表
cslink *cslink_combine(cslink *head1, cslink *head2)
{
    cslink *new_head = NULL,
            *tmp_head = NULL,
            *next = NULL;

    while (head1 || head2) {
        if (head1 && !head2) {
            next = head1;
        } else if (!head1 && head2) {
            next = head2;
        } else if (head1 && head2) {
            if (head1->c <= head2->c) {
                next = head1;
            } else {
                next = head2;
            }
        }

        if (next == head1) {
            head1 = head1->next;
        } else if (next == head2) {
            head2 = head2->next;
        }

        if (!new_head) {
            tmp_head = new_head = next;
        } else {
            tmp_head->next = next;
            tmp_head = next;
        }
    }

    return new_head;
}


int main()
{
    cslink *head1 = cslink_init("abc");
    cslink *head2 = cslink_init("a");

    cslink *head = cslink_combine(head1, head2);
    cslink_print(head);
}


