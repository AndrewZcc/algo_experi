/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_3_4_MINIMUMPARTITION_H
#define TEN_EIGHT_ALGORITHM_3_4_MINIMUMPARTITION_H

#include <iostream>

using namespace std;

// Method-1: Recursive Method
int MinSubsetPartition(int* arr, int len, int sumCount, int sumTotal)
{
    if (len == 0)
        return abs(sumCount - (sumTotal-sumCount));

    return min(
            // Case-1: include the last element in First-Subset
            MinSubsetPartition(arr, len-1, sumCount+arr[len-1], sumTotal),
            // Case-2: exclude the last element in First-Subset
            MinSubsetPartition(arr, len-1, sumCount, sumTotal) );
}

// Method-2: Dynamic Programming
int MinSubsetPartitionDP(int* arr, int n)
{
    int sum = 0;
    for (int i=0; i<n; i++) sum += arr[i];

    bool dp[n+1][sum+1];

    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=sum; i++)
        dp[0][i] = false;

    // Construct the Cache-Table (Bottom-Up Manner)
    for (int i=1; i<=n; i++)
        for (int j=1; j<=sum; j++)
        {
            // Default: i-th element is excluded
            dp[i][j] = dp[i-1][j];

            // Determine if i-th element can be included
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }

    int diff = INF;
    for (int j = sum/2; j>=0; j--)
        if (dp[n][j] == true)
        {
            diff = sum - 2*j;
            break;
        }

    return diff;
}

#endif //TEN_EIGHT_ALGORITHM_3_4_MINIMUMPARTITION_H
