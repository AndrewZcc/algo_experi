/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_7_QUICKSORT_H
#define TEN_EIGHT_ALGORITHM_4_7_QUICKSORT_H

int partition(int* arr, int l, int h)
{
    // step-1: select a pivot
    int pivot = arr[h];
    int pos = l - 1;

    // step-2: compare and move smaller-data to front, get the right position of pivot.
    for (int j = l; j <= h-1; j++) {
        if (arr[j] <= pivot) {
            pos++;
            swap(arr[pos], arr[j]);
        }
    }

    // step-3: put the pivot into its right-position
    swap(arr[h], arr[pos+1]);

    return (pos+1);
}

void QuickSort(int* arr, int l, int h)
{
    if (l < h)
    {
        int div = partition(arr, l, h);
        cout << "after partition: "; printArr(arr, 7);

        QuickSort(arr, l, div-1);
        QuickSort(arr, div+1, h);
    }
}

#endif //TEN_EIGHT_ALGORITHM_4_7_QUICKSORT_H
