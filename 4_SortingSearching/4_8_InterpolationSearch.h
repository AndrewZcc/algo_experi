/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_8_INTERPOLATIONSEARCH_H
#define TEN_EIGHT_ALGORITHM_4_8_INTERPOLATIONSEARCH_H

/**
 * 插值搜索(Interpolation Search): 适用于 在均匀分布的有序数组上的元素查找!
 *  - 本质上, 它是 Binary Search 在有序数组上进行搜索 的一种变体(优化)
 */
int InterpolationSearch(int* arr, int len, int key)
{
    int low = 0, high = len-1;

    while (low <= high)
    {
        // 计算 插值 的位置 (利用均匀分布的特性)
        int search = low + ((key - arr[low])/(arr[high] - arr[low]))*(high-low);

        if (arr[search] == key) return search;
        if (arr[search] < key) low = search+1;
        else high = search-1;
    }

    return -1;
}

#endif //TEN_EIGHT_ALGORITHM_4_8_INTERPOLATIONSEARCH_H
