#include <iostream>
#include "3_1_LongestCommonSubsequence.h"
#include "3_2_LongestIncreasingSubsequence.h"
#include "3_3_EditDistance.h"
#include "3_4_MinimumPartition.h"

using namespace std;

void main_3_DynamicProgramming()
{
    /*
    // 3_1 LCS Longest Common Subsequence
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    cout << "m = " << m << ", n = " << n << endl;
    LCS(X, Y, m, n);

    // 3_2_LIS Longest Increasing Subsequence
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int len = sizeof(arr)/sizeof(arr[0]);
    LIS(arr, len);

    // 3_3 Edit-Distance
    string str1 = "Sunday";
    string str2 = "Saturday";
    cout << "M1(Recursive): " << str1 << " -> " << str2 << ", Need " << editDistance(str1, str2) << " operations." << endl;
    cout << "M2(Dynamic-Prog): " << str1 << " -> " << str2 << ", Need " << editDistanceDP(str1, str2) << " operations." << endl;
    */

    // 3_4 Minimum Partition
    int arr[] = {3, 1, 4, 2, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sumTotal = 0;
    for (int i=0; i<len; i++) sumTotal += arr[i];
    cout << "M1(Recursive): Minimum difference between two sets is: " << MinSubsetPartition(arr, len, 0, sumTotal) << endl;
    cout << "M2(Dynamic-Prog): Minimum difference between two sets is: " << MinSubsetPartitionDP(arr, len) << endl;

}