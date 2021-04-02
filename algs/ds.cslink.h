#include <string.h>
#include <stdlib.h>

typedef struct _cslink {
    char c;
    struct _cslink *next;
} cslink;

// 创建一个新节点
cslink *cslink_create(char c)
{
    cslink *node = malloc(sizeof(cslink));
    node->c = c;
    node->next = NULL;
    return node;
}

// 将节点插入到单链表的尾部
cslink *cslink_add(cslink *head, cslink *node)
{
    if (!head) {
        head = node;
    } else {
        cslink *tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

// 用数据初始化链表
cslink *cslink_init(char *str)
{
    int len = strlen(str);
    cslink *tmp;

    tmp = malloc(len * sizeof(cslink));

    for (int i = 0; i < len; ++i) {
        tmp[i].c = str[i];
        tmp[i].next = (i == len - 1) ? NULL : &tmp[i + 1];
    }

    return cslink_add(NULL, tmp);
}

// 返回单链表最后一个元素
cslink *cslink_last(cslink *head)
{
    while (head->next) {
        head = head->next;
    }

    return head;
}

// 返回单链表第 n 个元素
cslink *cslink_get(cslink *head, int n)
{
    for (int i = 0; i < n; ++i) {
        head = head->next;
    }

    return head;
}

// 快慢指针法, 返回环的起始节点
cslink *cslink_detect_cycle(cslink *head)
{
    cslink *pre = head, *cur = head;
    if (!pre || !pre->next)
        return NULL;
    while (pre && pre->next) {
        cur = cur->next;
        pre = pre->next->next;
        if (cur == pre)
            break;
    }

    if (cur != pre) {
        return NULL;
    }

    pre = head;
    while (pre != cur) {
        pre = pre->next;
        cur = cur->next;
    }
    return cur;
}

// 单链表反转, 返回反转后的链头
cslink *cslink_reverse(cslink *head)
{
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }

    cslink *tmp;
    cslink *tmp2;

    tmp = head->next;
    tmp2 = head->next->next;

    head->next = NULL;
    while (tmp) {
        tmp->next = head;
        head = tmp;
        tmp = tmp2;
        if (tmp2) {
            tmp2 = tmp2->next;
        }
    }

    return head;
}

// 删除指定的节点
cslink *cslink_remove(cslink *head, cslink *node)
{
    if (!head) return NULL;

    cslink *next = head->next,
            *prev = NULL,
            *cur = head;
    while (cur && cur != node) {
        prev = cur;
        cur = cur->next;
        if (!next) {
            // out of index
            return NULL;
        }
        next = next->next;
    }

    // delete
    if (prev) {
        prev->next = next;
    } else {
        head = next;
    }

    return cur;
}

// 按位置删除节点
cslink *cslink_delete(cslink *head, int n)
{
    if (!head) return NULL;

    int total = n,
            i = 0;
    if (n < 0) {
        // 倒数
        total = -n - 1;
        head = cslink_reverse(head);
    }

    cslink *next = head->next,
            *prev = NULL,
            *cur = head;
    for (; i < total; ++i) {
        prev = cur;
        cur = cur->next;

        if (!next) {
            // out of index
            return NULL;
        }
        next = next->next;
    }

    // n 超出最大范围
    if (i < total) {
        return NULL;
    }

    // delete
    if (prev) {
        prev->next = next;
    } else {
        head = next;
    }

    if (n < 0) {
        head = cslink_reverse(head);
    }

    return cur;
}

// 打印链表节点的数据
void cslink_print(cslink *head)
{
    cslink *tmp = head;
    cslink *cycle_start = cslink_detect_cycle(head);
    if (cycle_start) {
        int cycle_start_access_count = 0;
        while (tmp) {
            if (tmp == cycle_start) {
                cycle_start_access_count++;
            }
            if (cycle_start_access_count == 2) {
                break;
            }
            printf("%c", tmp->c);
            tmp = tmp->next;
        }
    } else {
        while (tmp) {
            printf("%c", tmp->c);
            tmp = tmp->next;
        }
    }
}
