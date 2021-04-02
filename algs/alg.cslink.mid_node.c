#include <stdio.h>
#include "ds.cslink.h"

cslink *cslink_mid_node(cslink *head)
{
    cslink *slow = head,
            *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // if (!fast) {
    //     slow = slow->next;
    // }

    return slow;
}

// 求链表的中间节点, 奇数返回中间的, 偶数返回第二个中间的
int main()
{
    cslink *head1 = cslink_init("abcd");
    printf("%c\n", cslink_mid_node(head1)->c);

    cslink *head2 = cslink_init("abcde");
    printf("%c\n", cslink_mid_node(head2)->c);
}

