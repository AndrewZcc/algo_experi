/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_PAIRWISEREVERSELIST_H
#define TEN_EIGHT_ALGORITHM_PAIRWISEREVERSELIST_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

// Pair-wise Reverse List
Node* reversePairwise(Node** head)
{
    // 考虑 两种基本情况: 没有元素怎么办, 有一个元素怎么办
    Node* prev = *head;
    if (prev == NULL) return NULL;
    Node* last = prev->next;
    if (last == NULL) return prev;

    // 考虑 两个元素 都有的情形
    if (prev && last) {
        prev->next = last->next;
        last->next = prev;
    }

    // 递归的调用
    prev->next = reversePairwise(&prev->next);

    return last;
}

#endif //TEN_EIGHT_ALGORITHM_PAIRWISEREVERSELIST_H
