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
#include "2_5_MergeAlternateLinkedList.h"
#include "2_6_ReverseLinkedList.h"
#include "2_7_UnionANDIntersection.h"
#include "2_8_DetectRemoveLoop.h"
#include "2_9_MergeSortLinkedList.h"
#include "2_A_RandomNodeOneTraversal.h"

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

    // 2-5 merge linked-list at alternate positions
    Node* l1 = NULL;
    //new Node(1); addNode(&l1, 2); addNode(&l1, 3);
    Node* l2 = new Node(4);
    addNode(&l2, 5); addNode(&l2, 6); addNode(&l2, 7); addNode(&l2, 8);

    mergeLinkedList(&l1, &l2);

    cout << "After Merge: "<< endl;
    cout << "L1: "; printLinkedList(l1);
    cout << "L2: "; printLinkedList(l2);

    // 2-6 reverse a linked-list
    Node* list = new Node(1);
    addNode(&list, 2); addNode(&list, 3); addNode(&list, 4); addNode(&list, 5);
    //cout << "Before Reverse: "; printLinkedList(list);
    //reverse(&list);
    //cout << "After Reverse: "; printLinkedList(list);
    // Method-1: reverseLinkedList(&list, 3);
    // Method-2: Recursion-Method
    cout << "After reverse{3}, "; printLinkedList(reverseGeeks(list, 3));

    // 2-7 union and intersection
    Node* l1 = new Node(10); addNode(&l1, 15); addNode(&l1, 4); addNode(&l1, 20);
    Node* l2 = new Node(8); addNode(&l2, 4); addNode(&l2, 2); addNode(&l2, 10);
    cout << "L1 = "; printLinkedList(l1);
    cout << "L2 = "; printLinkedList(l2);
    cout << "Union List: "; printLinkedList(unionList(l1, l2));
    cout << "Intersect List: "; printLinkedList(intersectList(l1, l2));

    // 2-8 detect and remove linked-list loop.
    // {注意: 利用到了 Floyd Cycle Detection Algorithm. [ More Faster, More Stronger] }
    Node* l1 = new Node(0); addNode(&l1, 1); addNode(&l1, 2); addNode(&l1, 3);
    addNode(&l1, 4); addNode(&l1, 5); addNode(&l1, 6); addNode(&l1, 7);
    Node* temp = l1->next->next->next->next;
    temp = temp->next->next->next->next = l1; // l1->next;
    // printLinkedList(l1); --> 此时形成了环, 打印链表的时候 崩溃了

    cout << "L1 has loop? "; FloydCycleDetect(l1) ? cout << "Yes" << endl : cout << "No" << endl;

    if (DetectRemoveLoop(&l1))
    {
        cout << "L1 has loop! And the loop is removed! " << endl;
        cout << "After Remove Loop, "; printLinkedList(l1);
    } else {
        cout << "L1 has NOT loop!" << endl;
    }
    */

    // 2-9 MergeSort for linked-list!
    Node* list1 = new Node(20);
    Node* list2 = new Node(20); addNode(&list2, 14); addNode(&list2, 24);
    Node* list3 = new Node(20); addNode(&list3, 14); addNode(&list3, 24); addNode(&list3, 10);

    cout << "list-1, "; printLinkedList(list1);
    MergeSort(&list1);
    cout << "After merge-sort: "; printLinkedList(list1);
    cout << endl;
    cout << "list-2, "; printLinkedList(list2);
    MergeSort(&list2);
    cout << "After merge-sort: "; printLinkedList(list2);
    cout << endl;
    cout << "list-3, "; printLinkedList(list3);
    MergeSort(&list3);
    cout << "After merge-sort: "; printLinkedList(list3);
    cout << endl;

    // 2-10 Generate random linked-list node in one traversal
    randTest();
    printLinkedList(list3);
    printRandom(list3);
    sleep(2);   // 进程等待 2 s, 从而使 随机数种子 发生变化
    printRandom(list3);
    sleep(2);   // 进程等待 2 s, 从而使 随机数种子 发生变化
    printRandom(list3);
    sleep(2);   // 进程等待 2 s, 从而使 随机数种子 发生变化
    printRandom(list3);
}

#endif //TEN_EIGHT_ALGORITHM_MAIN_H
