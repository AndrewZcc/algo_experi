#include <iostream>
#include "3_1_LongestCommonSubsequence.h"
#include "3_2_LongestIncreasingSubsequence.h"

using namespace std;

void main_3_DynamicProgramming()
{
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

}