/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_5_MERGEALTERNATELINKEDLIST_H
#define TEN_EIGHT_ALGORITHM_2_5_MERGEALTERNATELINKEDLIST_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

void mergeLinkedList(Node** l1, Node** l2)
{
    Node* temp = *l1;

    // 合并进入 空链表
    if (temp == NULL)
    {
        *l1 = *l2;

        if (*l2 != NULL) {
            Node* post = (*l2)->next;;
            (*l2)->next = NULL;
            *l2 = post;
        }

        return;
    }

    // 合并进入 正常链表
    while (temp)
    {
        Node* post = temp->next;

        if ((*l2) != NULL) {
            temp->next = *l2;
            *l2 = (*l2)->next;
            temp->next->next = post;
        }

        temp = post;
    }
}

#endif //TEN_EIGHT_ALGORITHM_2_5_MERGEALTERNATELINKEDLIST_H
