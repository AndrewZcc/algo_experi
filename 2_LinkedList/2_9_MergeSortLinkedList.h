/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_9_MERGESORTLINKEDLIST_H
#define TEN_EIGHT_ALGORITHM_2_9_MERGESORTLINKEDLIST_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

using namespace std;

/**
 * 归并排序 (Merge-Sort): 在 Linked-List 中会有更好的表现 (为什么?)
 *
 * 因为: 归并排序 不需要交换任何元素, 只需要修改指针 即可!
 */

// --- Func 1: split a linked-list into two parts
void FrontBackSplit(Node* source, Node** a, Node** b)
{
    Node* fast, *slow;

    // 链表为 空链表 或 链表中只含一个元素
    if (source == NULL || source->next == NULL)
    {
        *a = source;
        *b = NULL;
    } else {
        slow = source;
        fast = source->next;

        while (fast != NULL)    // 这样就将 原链表 拆分成两段
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *a = source;
        *b = slow->next;
        slow->next = NULL;  // 通过这一条语句: 将原先的一个链表,拆分成为了两个链表
    }
}

void splitLinkedList(Node* head, Node** mid)
{
    Node *fast = head;
    *mid = head;

    while (fast != NULL && fast->next != NULL && (*mid) != NULL)
    {
        fast = fast->next->next;
        (*mid) = (*mid)->next;
    }
}

// ----------- Func 2 -------------
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data)
    {
        result = a;
        // 运用 递归 (剩下来的部分又可以建模成为一个相同的子问题)
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        // 运用 递归 (剩下来的部分又可以建模成为一个相同的子问题)
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

Node* SortedMerge2(Node* a, Node* b)
{
    Node* result = NULL;
    Node* tail;

    while (true)
    {
        if (a == NULL || b == NULL) break;

        if (a->data <= b->data) {   // 较小元素是 a
            if (result == NULL) {
                result = a;
                tail = result;
            }
            else tail->next = a;

            a = a->next;

        } else {    // 较小元素是 b
            if (result == NULL) {
                result = b;
                tail = result;
            }
            else tail->next = b;

            b = b->next;
        }

        tail = tail->next;
    }

    while (a)
    {
        tail->next = a;
        tail = tail->next;
        a = a->next;
    }
    while (b)
    {
        tail->next = b;
        tail = tail->next;
        b = b->next;
    }

    return result;
}
// ------- Func 3 -------------
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node *a, *b;

    // 递归终止条件 linked-list length = 0|1.
    if (head == NULL || head->next == NULL)
        return;

    // 将一个 list 划分成两个子链表 a 与 b
    FrontBackSplit(head, &a, &b);

    cout << "After Split: a = "; printLinkedList(a);
    cout << "After Split: b = "; printLinkedList(b);

    // 递归划分这两个子链表
    MergeSort(&a);
    MergeSort(&b);
    cout << "After Sort: a = "; printLinkedList(a);
    cout << "After Sort: b = "; printLinkedList(b);

    // 合并 这两个 已经排序好的子链表部分
    *headRef = SortedMerge(a, b);
}

void MergeSort2(Node** list)
{
    Node* mid = NULL;
    splitLinkedList(*list, &mid);

    if (mid != *list)
    {
        //MergeSortLinkedList()
    }
}

#endif //TEN_EIGHT_ALGORITHM_2_9_MERGESORTLINKEDLIST_H
