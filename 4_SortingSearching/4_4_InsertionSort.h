/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_4_INSERTIONSORT_H
#define TEN_EIGHT_ALGORITHM_4_4_INSERTIONSORT_H

/**
 * 插入排序: repeatedly pick element arr[i], insert it into sorted-sequence arr[0..i-1]
 */
void InsertionSort(int* arr, int len)
{
    int i, j;

    for (i=1; i < len; i++) {
        int current = arr[i];

        // 不断遍历 sorted-array arr[0..i-1] 找出 当前值current 在sorted-array中的正确位置
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > current)
                swap(arr[j], arr[j+1]);
            else break;
        }
        // insert the current-value into right position.
        arr[j+1] = current;

        cout << i << ": "; printArr(arr, len);
    }
}

#endif //TEN_EIGHT_ALGORITHM_4_4_INSERTIONSORT_H
