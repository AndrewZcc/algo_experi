#include <iostream>
#include "4_1_BinarySearch.h"
#include "4_2_BinarySearchRotate.h"
#include "4_3_BubbleSort.h"
#include "4_4_InsertionSort.h"

using namespace std;

void main_4_SortingSearching()
{
    /*
    //cout << "Sorting and Searching Algorithm." << endl;
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
}