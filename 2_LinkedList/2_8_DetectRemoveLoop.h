/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_8_DETECTREMOVELOOP_H
#define TEN_EIGHT_ALGORITHM_2_8_DETECTREMOVELOOP_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

using namespace std;

/**
 * 检测 有没有回路 的方法有三种:
 * Method-1. Mark Visited Nodes; ( Naive algorithm. 特点: 最简单直接)
 * Method-2. Hash Method; (特点: 思想等同于Method-1,不过不需额外空间)
 * Method-3. Floyd's Cycle-Finding Algorithm. [又被称做'龟兔循环检测算法']
 *          (Fastest Method: using two linkers.)
 */
bool FloydCycleDetect(Node* head)
{
    Node *hare = head, *tortoise = head;

    while (hare != NULL && tortoise != NULL)    // 兔 每次走两步,所以如果不存在回路,那么这个循环将会很快结束
                                                // 兔 到终点后,需要 等龟爬过来, 共同判定循环结束。
    {
        tortoise = tortoise->next;      // 龟 走一步

        if (hare->next != NULL)
            hare = hare->next->next;    // 兔 走两步

        if (hare == tortoise)   // 如果两者再次相遇, 则代表这条路径中存在回路(cycle)
            return true;
    }

    return false;
}

void removeLoop(Node *loop_node, Node **list_head)
{
    Node *ptr1, *ptr2;

    ptr1 = *list_head;
    while(true)
    {
        ptr2 = loop_node;

        while (ptr2->next != loop_node && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if (ptr2->next == ptr1) break; // 导致循环产生的 源头 被找到!

        ptr1 = ptr1->next;
    }

    ptr2->next = NULL;  // remove the loop.
}

bool DetectRemoveLoop(Node** list)
{
    Node *hare = *list, *tortoise = *list;

    while (hare != NULL && tortoise != NULL)
    {
        tortoise = tortoise->next;

        if (hare->next != NULL)
            hare = hare->next->next;

        if (hare == tortoise)
        { // 发现了 环 ( Loop Detected!), 接下来是:移除循环的工作
            removeLoop(tortoise, list);

            return true;
        }
    }

    return false;
}

#endif //TEN_EIGHT_ALGORITHM_2_8_DETECTREMOVELOOP_H
