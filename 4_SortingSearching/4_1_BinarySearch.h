/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_1_BINARYSEARCH_H
#define TEN_EIGHT_ALGORITHM_4_1_BINARYSEARCH_H

#include <iostream>

using namespace std;

void printArr(int* arr, int len)
{
    for (int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 * 用 递归(recursive) 的方式实现 BinarySearch.
 * 成功 简化参数个数! 更简洁明了!
 */
int BinarySearch(int* arr, int start, int end, int key)
{
    int mid = (start + end) / 2;

    if (start <= end)
    {
        cout << "key = " << key << ", arr["<<mid<<"] = " << arr[mid] << endl;
        if (key == arr[mid])
            return mid;

        if (key < arr[mid]) {
            return BinarySearch(arr, start, mid-1, key);
        }
        else {
            return BinarySearch(arr, mid+1, end, key);
        }
    }

    return -1;
}

#endif //TEN_EIGHT_ALGORITHM_4_1_BINARYSEARCH_H
