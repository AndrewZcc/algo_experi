/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_10_RANDOMNODEONETRAVERSAL_H
#define TEN_EIGHT_ALGORITHM_2_10_RANDOMNODEONETRAVERSAL_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

using namespace std;

/**
 * "蓄水池采样"(Reservoir Sampling) 的应用:
 * 从 不确定个元素中 等概率的随机选出 1 个元素! (此时蓄水池大小为 1)
 */
void printRandom(Node* head)
{
    if (head == NULL)
    {
        cout << "The List is Empty!" << endl;
        return;
    }

    srand(time(NULL));
    int result = head->data;
    Node* current = head;

    for (int n = 2; current != NULL; n++)
    {
        // 随机产生一个 [0...n-1] 的数字, 如果这个数字在蓄水池内(等于0),则将蓄水池内的水替换掉
        // 如果 随机出来的不在 采样蓄水池 内, 则将其直接忽略(也即不采样)!
        if (rand() % n == 0) {
            result = current->data;
        }

        current = current->next;
    }

    cout << "The Randomly selected data is: " << result << endl;
}

// 根据初始化的 随机数种子 产生 10个不同的随机数
void randTest()
{
    srand(time(NULL));
    for(int i = 0; i < 10;i++ )
        cout << rand() << ' ';
    cout << endl << endl;
}

#endif //TEN_EIGHT_ALGORITHM_2_10_RANDOMNODEONETRAVERSAL_H
