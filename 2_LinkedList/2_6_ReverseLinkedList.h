/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_6_REVERSELINKEDLIST_H
#define TEN_EIGHT_ALGORITHM_2_6_REVERSELINKEDLIST_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

void reverse(Node** temp)
{
    if ((*temp) == NULL) return;

    Node *prev = NULL, *here = (*temp), *post;

    // 通过 循环 不断修改链表指针方向
    while (here != NULL)
    {
        post = here->next;
        here->next = prev;
        prev = here;
        here = post;
    }

    // 最后 再将 链表头重新定位到原链表尾(此时prev指向链表尾) 即可
    *temp = prev;
}

/**
 * IDEA-1: 将其分段, 然后按段进行反转 !!- 有 Bug -!!
 */
void reverseLinkedList(Node** l, int len)
{
    Node *div = *l, *prev;

    while (div != NULL) {
        Node* head = div;

        for (int i = 0; i < len && div != NULL; i++) {
            prev = div;
            div = div->next;
        }

        prev->next = NULL;
        Node *tail = head;
        cout << "try ..." << endl;
        reverse(&head);
        cout << "1: Reverse head: "; printLinkedList(head);
        *l = head; // head 的值 已经发生了改变 (reverse 成了原List的尾Node)
        tail->next = div;
        cout << "2: Reverse head: "; printLinkedList(*l);
    }

    cout << "List l = "; printLinkedList(*l);
}

/**
 * IDEA-2: 采用 递归 的方法: 对一个List进行反转
 */
Node* reverseGeeks(Node* head, int k)
{
    Node *current = head, *next = NULL, *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseGeeks(next, k);

    return prev;
}

#endif //TEN_EIGHT_ALGORITHM_2_6_REVERSELINKEDLIST_H
