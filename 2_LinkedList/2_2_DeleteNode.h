/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_2_DELETENODE_H
#define TEN_EIGHT_ALGORITHM_2_2_DELETENODE_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

using namespace std;

void addNode(Node** head, int entry)
{
    if (*head == NULL) *head = new Node(entry);
    else {
        Node* i = *head;
        while (true) {
            if (i->next == NULL) break;
            i = i->next;
        }
        i->next = new Node(entry);
    }
}

void deleteNode(Node* head, Node* node)
{
    // Case-1: 删除头结点
    if (head == node)
    {
        cout << "Case-1: delete head!" << endl;
        head->data = head->next->data;
        head->next = head->next->next;
        delete(head->next);
    } else {
        /**
         * Case-2: 删除中间节点: 滑动窗口 的方法定位要删除的节点!
         */
        cout << "Case-2: delete other!" << endl;
        Node* prev = head;

        while (prev->next != NULL && prev->next != node )
            prev = prev->next;

        if (prev->next == NULL) {
            cout << "This Node (" << node->data << ") not found!" << endl;
            return;
        } else {
            //cout << "delete " << i->data << ", prev = " << prev->data<< endl;
            // 使用滑动窗口 把 节点i 删除掉
            prev->next = prev->next->next;
            //delete(node);
        }
    }
}


#endif //TEN_EIGHT_ALGORITHM_2_2_DELETENODE_H
