/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_3_BUBBLESORT_H
#define TEN_EIGHT_ALGORITHM_4_3_BUBBLESORT_H

/**
 * 算法思想: repeatedly swapping the adjacent elements if they are in wrong order.
 */
void BubbleSort(int* arr, int len)
{
    for (int i = len-1; i >=0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
        cout << i << ": "; printArr(arr, len);
    }
}

#endif //TEN_EIGHT_ALGORITHM_4_3_BUBBLESORT_H
