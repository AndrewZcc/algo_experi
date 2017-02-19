#include <iostream>
#include "4_1_BinarySearch.h"
#include "4_2_BinarySearchRotate.h"
#include "4_3_BubbleSort.h"
#include "4_4_InsertionSort.h"
#include "4_5_MergeSort.h"
#include "4_6_HeapSort.h"
#include "4_7_QuickSort.h"
#include "4_8_InterpolationSearch.h"

using namespace std;

void main_4_SortingSearching()
{
    /* ***---------- Searching (part-1) ------------*** */
    /*
    int sortedArr[] = {4, 10, 23, 25, 31, 35};

    // 4-1: Binary Search (Using Recursive Algorithm)
    int sALen = sizeof(sortedArr)/sizeof(sortedArr[0]);
    cout << "Sorted Array: "; printArr(sortedArr, sALen);

    int key;
    while (cin >> key)
    {
        if (key == -1) break;

        int index = BinarySearch(sortedArr, 0, sALen-1, key);
        cout << "Index = " << index << endl;
        index != -1 ? cout << "FOUND, index = " << index << endl : cout << "Not Found!" << endl;
    }

    // 4-2: Binary Search for Rotate-Sorted-Array [二分查找算法变体]
    int rotateArr[] = {10, 14, 17, 23, 29, 32, 3, 6, 8};
    int key;
    while (cin >> key)
    {
        if (key == -1) break;

        int index = BinarySearchRotate(rotateArr, 0, (sizeof(rotateArr)/sizeof(rotateArr[0]))-1, key);
        cout << "Index = " << index << endl;
        index != -1 ? cout << "FOUND, index = " << index << endl : cout << "Not Found!" << endl;
    }
    */

    /* ***---------- Sorting ------------*** */
    /*
    // 4-3: Bubble Sort
    int arr[] = {10, 8, 12, 14, 6, 30, 11};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Bubble sort: "; printArr(arr, len);
    BubbleSort(arr, len);
    cout << "After sort: "; printArr(arr, len);
    cout << "---- END ----\n" << endl;

    // 4-4: Insertion Sort
    int arr2[] = {10, 8, 12, 14, 6, 30, 11};
    len = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Insertion sort: "; printArr(arr2, len);
    InsertionSort(arr2, len);
    cout << "After sort: "; printArr(arr2, len);
    cout << "---- END ----\n" << endl;

    // 4-5: Merge Sort
    int arr3[] = {10, 8, 12, 14, 6, 30, 11};
    len = sizeof(arr3)/sizeof(arr[0]);
    cout << "Merge sort: "; printArr(arr3, len);
    MergeSort(arr3, 0, len-1);
    cout << "After sort: "; printArr(arr3, len);
    cout << "---- END ----\n" << endl;

    // 4-6: Heap Sort (Binary Heap: a variant of Complete-Binary-Tree)
    int arr4[] = {10, 8, 12, 14, 6, 30, 11};
    len = sizeof(arr4)/sizeof(arr4[0]);
    cout << "Heap sort: "; printArr(arr4, len);
    HeapSort(arr4, len);
    cout << "After sort: "; printArr(arr4, len);
    cout << "---- END ----\n" << endl;

    // 4-7: Quick Sort (pick a pivot, and take it into right position.)
    int arr5[] = {10, 8, 12, 14, 6, 30, 11};
    len = sizeof(arr5)/sizeof(arr5[0]);
    cout << "Quick sort: "; printArr(arr5, len);
    QuickSort(arr5, 0, len-1);
    cout << "After sort: "; printArr(arr5, len);
    cout << "---- END ----\n" << endl;
    */

    /* ***---------- Searching (part-2) ------------*** */
    // 4-8: Interpolation Search (search on a sorted array with uniformly distributed values.)
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int len = sizeof(arr)/sizeof(arr[0]);
    int key;
    while (cin >> key)
    {
        if (key == -1) break;

        int pos = InterpolationSearch(arr, len, key);

        pos == -1 ? cout << "Not Found!" << endl : cout << "Founded! index = " << pos << endl;
    }
}