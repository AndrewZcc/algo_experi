/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_LinkedList_MAIN_H
#define TEN_EIGHT_ALGORITHM_2_LinkedList_MAIN_H

#include <iostream>
#include "2_1_InsertionSortedList.h"
#include "2_2_DeleteNode.h"

using namespace std;

void main_2_LinkedList()
{
    /*
    // 2-1 Insert Sorted Linked-List
    Node* head = NULL;
    int entry;
    while (cin >> entry)
    {
        if (entry == -1) break;

        // 向 head 为头的链表中插入 新元素
        insertNode(&head, entry);
        printLinkedList(head);
    }
    */

    // 2-2 Delete Linked-List Node
    Node* head = new Node(5);
    addNode(&head, 4);
    addNode(&head, 6);
    addNode(&head, 9);
    addNode(&head, 1);
    addNode(&head, 8);
    printLinkedList(head);

    deleteNode(head, head);
    cout << "After delete head: ";
    printLinkedList(head);

    deleteNode(head, head->next->next);
    cout << "After delete next-2: " << endl;
    printLinkedList(head);
}

#endif //TEN_EIGHT_ALGORITHM_MAIN_H
