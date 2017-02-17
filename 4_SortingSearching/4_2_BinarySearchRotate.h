/**
 * 对于有序数组内的查找: 二分查找是目前效率最高的查找方法 (O(Log N))
 * - 对于任何 有序数组 的变体: 比如 旋转有序数组 等。
 *   只要要求查找效率为 O(Log N), 那么该算法也必然是 二分查找 的变体!【比如:本题】
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_2_BINARYSEARCHROTATE_H
#define TEN_EIGHT_ALGORITHM_4_2_BINARYSEARCHROTATE_H

#include "4_1_BinarySearch.h"

/**
 * 用 二分查找 的方式找出旋转点pivot -> 复杂度 O(Log N)
 */
int FindRotatePivot(int* arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (mid >= start+1 && mid <= end)
    {
        if (arr[mid] < arr[mid-1]) return mid;

        return FindRotatePivot(arr, mid+1, end);
    }

    return -1;
}

/**
 * 再以 pivot 为分割点, 分别对左右两个 有序数组进行 二分查找 ->  复杂度保持 O(Log N)
 */
int BinarySearchRotate(int* arr, int start, int end, int key)
{
    int pivot = FindRotatePivot(arr, start, end);
    cout << "Pivot index = " << pivot << endl;

    if (pivot == -1)
        return BinarySearch(arr, start, end, key);

    if (key == arr[pivot])
        return pivot;

    // 从 key 可能出现的部分开始搜索, 切记:搜索不要有遗漏。
    if (key >= arr[start])
        return BinarySearch(arr, start, pivot-1, key);
    return BinarySearch(arr, pivot+1, end, key);
}

#endif //TEN_EIGHT_ALGORITHM_4_2_BINARYSEARCHROTATE_H
