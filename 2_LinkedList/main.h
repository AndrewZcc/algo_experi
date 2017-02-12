/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_LinkedList_MAIN_H
#define TEN_EIGHT_ALGORITHM_2_LinkedList_MAIN_H

#include <iostream>
#include "2_1_InsertionSortedList.h"
#include "2_2_DeleteNode.h"
#include "2_3_CompareStrings.h"
#include "2_4_AddNumbers.h"

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

    // 2-2 Delete Linked-List Node
    Node* head = new Node(5);
    addNode(&head, 4);
    addNode(&head, 6);
    addNode(&head, 9);
    addNode(&head, 1);
    addNode(&head, 8);
    printLinkedList(head);

    deleteNode(head, head);
    cout << "After delete head: " << endl;
    printLinkedList(head);

    deleteNode(head, head->next->next);
    cout << "After delete next-2: " << endl;
    printLinkedList(head);

    // 2-3 compare two-strings represent as Linked-Lists
    charNode* charList1 = NULL;
    insertString(&charList1, "geeksb");
    charNode* charList2 = NULL;
    insertString(&charList2, "geeksb");
    insertString(&charList2, "abc");
    printLinkedList(charList1);
    printLinkedList(charList2);
    cout << "compare(str1, str2) = " << compare(charList1, charList2) << endl;
    */

    // 2-4 add two-numbers represent as Linked-Lists
    Node* numList1 = new Node(9);
    numList1->next = new Node(9);
    numList1->next->next = new Node(9);
    cout << "numList1 = " << numList2Int(numList1) << endl;
    Node* numList2 = new Node(1);
    numList2->next = new Node(8);
    cout << "numList2 = " << numList2Int(numList2) << endl;

    Node* result = NULL;
    addNumbersLL(numList1, numList2, &result);
    cout << "Compute sum-List: "; printLinkedList(result);
}

#endif //TEN_EIGHT_ALGORITHM_MAIN_H
