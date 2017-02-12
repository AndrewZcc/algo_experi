/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_4_ADDNUMBERS_H
#define TEN_EIGHT_ALGORITHM_2_4_ADDNUMBERS_H

#include <iostream>
#include "2_1_InsertionSortedList.h"

// 把一个 NumList 按照 10进制 转换成 int
int numList2Int(Node* numList)
{
    int num = 0;
    if (numList == NULL) return 0;

    while (numList != NULL)
    {
        num = num * 10 + numList->data;
        numList = numList->next;
    }

    return num;
}

void addNodeInHead(Node** result, int data)
{
    Node* temp = *result;
    *result = new Node(data);
    (*result)->next = temp;
}

void addNumbersLL(Node* numList1, Node* numList2, Node** results)
{
    int num1 = numList2Int(numList1);
    int num2 = numList2Int(numList2);
    int sum = num1 + num2;

    // 把一个 int 值, 按位存储进一个 List !
    while (sum != 0)
    {
        addNodeInHead(results, sum % 10);
        sum = sum / 10;
    }
}

#endif //TEN_EIGHT_ALGORITHM_2_4_ADDNUMBERS_H
