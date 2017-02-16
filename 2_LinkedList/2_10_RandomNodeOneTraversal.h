/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_10_RANDOMNODEONETRAVERSAL_H
#define TEN_EIGHT_ALGORITHM_2_10_RANDOMNODEONETRAVERSAL_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

using namespace std;

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
        int mid = rand();
        if (mid % n == 0) {
            result = current->data;
            cout << "rand() = " << mid << ", n = " << n << ", ";
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
