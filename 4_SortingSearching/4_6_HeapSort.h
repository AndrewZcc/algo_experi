/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_6_HEAPSORT_H
#define TEN_EIGHT_ALGORITHM_4_6_HEAPSORT_H

#include <iostream>

using namespace std;

/**
 * 背景知识:
 *  - Binary-Heap: is a Complete Binary Tree where items are stored in a special order.
 *  - 一个 完全二叉树(Complete Binary Tree) 可以有两种表示方式: 1.binary-tree, 2.array.
 */

void heapify(int* arr, int len, int node)
{
    // 思想: 找出最大元素的数组下标,将其与根节点数值交换; 然后递归的处理已交换位置处的子树!
    int largest = node;
    int left = 2*node + 1;
    int right = 2*node + 2;

    if (left < len && arr[largest] < arr[left])
        largest = left;
    if (right < len && arr[largest] < arr[right])
        largest = right;

    if (largest != node)    // largest=node,代表根节点最大,不需进行交换
    {
        swap(arr[largest], arr[node]);
        heapify(arr, len, largest);
    }
}

void HeapSort(int* arr, int len)
{
    // Step-1: Build the Heap (from bottom to top)
    for (int i = len/2-1; i>=0; i--)
        heapify(arr, len, i);

    for (int i= len-1; i >=0; i--)
    {
        // Step-2: 此时将已经 堆化 的数据的 堆顶元素 与末尾值交换
        swap(arr[0], arr[i]);
        cout << "swap(0, "<<i<<"): "; printArr(arr, len);

        // Step-3: 重新对 堆顶位置 堆化即可! 因为堆顶元素的两个子堆本身就已经是 堆了!
        heapify(arr, i, 0);
    }
}

#endif //TEN_EIGHT_ALGORITHM_4_6_HEAPSORT_H
