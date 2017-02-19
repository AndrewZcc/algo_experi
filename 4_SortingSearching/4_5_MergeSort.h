/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_4_5_MERGESORT_H
#define TEN_EIGHT_ALGORITHM_4_5_MERGESORT_H

/**
 * 合并两个 Sorted-Array
 */
void merge(int* arr, int l, int m, int r)
{
    int l_size = m-l+1;
    int r_size = r-m;

    int L[l_size];
    int R[r_size];

    // Copy two sub-sorted-array.
    for (int i=0; i<l_size; i++)
        L[i] = arr[l + i];          // 注意: 这里的l不是0, 所以 L[i] = arr[l+i] 而不是 arr[i].
    for (int i=0; i<r_size; i++)
        R[i] = arr[m + 1 + i];

    // Merge L,R into the origin-array arr.
    int i = 0, j = 0;
    int k = l;
    while (i < l_size && j < r_size)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements into origin-array arr.
    while (i < l_size)
    {
        arr[k] = L[i];
        i++, k++;
    }
    while (j < r_size)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

void MergeSort(int* arr, int l, int r)
{
    if (l < r)  // 如果 l = r (不用排序) 或是 l > r (非法输入)
    {
        int m = (l+r) / 2;      // ==优化==> m = l + (r-l)/2;

        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

#endif //TEN_EIGHT_ALGORITHM_4_5_MERGESORT_H
