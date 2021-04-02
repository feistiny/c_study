#include <stdio.h>
#include "ds.cslink.h"

int is_palindrome(cslink *head)
{
    cslink *slow, *fast, *prev, *tmp;
    prev = tmp = NULL;
    slow = fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }

    if (fast) {
        slow = slow->next;
    }

    while (slow) {
        if (prev->c != slow->c) {
            return -1;
        }
        slow = slow->next;
        prev = prev->next;
    }

    return 0;
}

// 单链表字符串的回文判断
int main()
{
    char *str = "abcdcba";
    cslink *head = cslink_init(str);
    // cslink_print(head);

    if (0 == is_palindrome(head)) {
        printf("%s is palindrome", str);
    } else {
        printf("%s is not palindrome", str);
    }
}


