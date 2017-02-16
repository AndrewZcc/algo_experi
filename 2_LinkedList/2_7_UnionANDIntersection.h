/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_7_UNIONANDINTERSECTION_H
#define TEN_EIGHT_ALGORITHM_2_7_UNIONANDINTERSECTION_H

#include <iostream>
#include <set>
#include "2_1_InsertionSortedList.h"
#include "2_2_DeleteNode.h"

using namespace std;

template <class T>
void printSet(set<T> entry)
{
    cout << "The Set contains: [ ";
    for (auto i = entry.begin(); i != entry.end(); i++)
        cout << *i << " ";
    cout << "]" << endl;
}

/**
 * Method: 利用 C++ STL 里的 set 这一数据结构, 高效的完成求 两个集合 并集 的任务!
 */
Node* unionList(Node* l1, Node* l2)
{
    set<int> entry;

    for (Node* i = l1; i != NULL; i = i->next)
        entry.insert(i->data);
    cout << "After insert L1 into set, "; printSet(entry);

    for (Node* i = l2; i != NULL; i = i->next)
        entry.insert(i->data);
    cout << "After insert L2 into set, "; printSet(entry);
    //cout << "union size = " << entry.size() << endl;

    Node* result = NULL;
    for (auto i=entry.begin(); i != entry.end(); i++)
        addNode(&result, *i);

    return result;
}

/**
 * Method: 利用 C++ STL 里的 set 这一数据结构, 高效的完成求 两个集合 交集 的任务!
 */
Node* intersectList(Node* l1, Node* l2)
{
    Node* result = NULL;
    set<int> entry;

    for (Node* i = l1; i != NULL; i = i->next)
        entry.insert(i->data);

    for (Node* i = l2; i != NULL; i = i->next)
        if (entry.find(i->data) != entry.end())     // find() 函数用于查找某一特定元素
            addNode(&result, i->data);

    return result;
}

#endif //TEN_EIGHT_ALGORITHM_2_7_UNIONANDINTERSECTION_H
