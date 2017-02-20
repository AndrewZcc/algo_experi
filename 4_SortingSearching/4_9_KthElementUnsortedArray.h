/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_9_KTHELEMENTUNSORTEDARRAY_H
#define TEN_EIGHT_ALGORITHM_4_9_KTHELEMENTUNSORTEDARRAY_H

#include <iostream>

using namespace std;

/**
 * 在一个 Unsorted-Array 中找第k个最小或最大的值的几种解决方案
 *  1. [Naive Solution] ---> O(nLogn)
 *      - sort the array using a O(nLogn) algorithm like MergeSort,HeapSort,etc.
 *      - return the k-th element in the sorted-array.
 *
 *  2. [Using Min/Max-Heap] ---> O(n + kLogn) better than O(nLogn)
 *      - create Min/Max-Heap to the given n elements;
 *      - call extractMin()/extractMax() k times.
 *
 *  3. [Using QuickSort/Pivot] ---> Average O(n), Worst O(n^2)
 */

/* Method-3: Pivot Method, QuickSort variant */
int partition2(int* arr, int l, int r)
{
    int pivot = arr[r];

    int pos = l - 1;
    for (int j = l; j<=r-1; j++) {
        if (arr[j] <= pivot) {
            pos++;
            swap(arr[j], arr[pos]);
        }
    }

    swap(arr[r], arr[pos+1]);
    return pos+1;
}
/**
 *  4. [Using Randomized-Pivot QuickSelect Method] ---> Expected Linear Time O(n)
 */
int randomPartition(int* arr, int l, int r)
{
    int len = r - l + 1;

    int pivot_pos = rand() % len;
    cout << "Random: " << pivot_pos << endl;
    swap(arr[ l + pivot_pos], arr[r]);      // Second-Time Note: l is the Base, not 0.

    return partition2(arr, l, r);
}

int KthSmallest(int* arr, int l, int h, int k)
{
    if (k > 0 && k <= (h-l+1))
    {
        //int divPos = partition2(arr, l ,h);
        int divPos = randomPartition(arr, l, h);

        if (divPos -l + 1 == k)             // First-Time Note: 一定要以 l 为起点, 而不是以 0 为起点.
            return arr[divPos];
        if (divPos -l + 1 > k)
            return KthSmallest(arr, l, divPos-1, k);
        return KthSmallest(arr, divPos+1, h, k-(divPos-l+1));
    }

    return -1;
}

#endif //TEN_EIGHT_ALGORITHM_4_9_KTHELEMENTUNSORTEDARRAY_H
