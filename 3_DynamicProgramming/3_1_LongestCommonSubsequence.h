/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_3_1_LONGESTCOMMONSUBSEQUENCE_H
#define TEN_EIGHT_ALGORITHM_3_1_LONGESTCOMMONSUBSEQUENCE_H

#include <iostream>

using namespace std;

/** ***********************************
 * Dynamic Programming Set-1: Overlapping Subproblems Property
 */
int lookup[1000];

void initialize()
{
    memset(lookup, -1, 1000);
}
// Solve common-sub-problems.
// Memorization Method: top down.
int fib1(int n)
{
    if (lookup[n] == -1)
    {
        if (n <= 1) lookup[n] = n;
        else lookup[n] = fib1(n-1) + fib1(n-2);
    }

    return lookup[n];
}
// Tabulation Method: bottom up.
int fib2(int n)
{
    int f[n+1];     // 利用一个数组来存储中间结果
    int i;  f[0] = 0; f[1] = 1;

    for (i=2; i<=n; i++)
        f[i] = f[i-1] + f[i-2];

    return f[n];
}

/** ***********************************
 * Dynamic Programming Set-2: Optimal Substructure Property
 *  - A given problems has Optimal Substructure Property if optimal solution of the given problem
 *    can obtained by using [optimal solutions] of its subproblems.
 *  - 参见 1_3/1_4: Shortest Path Algorithm [Dijistra Algo && Floyd Algo].
 */

/** ***********************************
 * Dynamic Programming Set-3: Longest Increasing Subsequence (LIS)
 *  - 参见 3_2_LongestIncreasingSubsequence.h
 */

/**
 * Dynamic Programming Set-4: Longest Common Subsequence (LCS)
 */
void LCS(char* X, char* Y, int m, int n)
{
    int length[m+1][n+1];

    // Construct the CommonSubsequence Length-Array
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
        {
            // Base-Case: Has Empty-String
            if (i == 0 || j == 0)
                length[i][j] = 0;
            // High-Case 1: No Empty-String && 最后一个字母相同
            else if (X[i-1] == Y[j-1])
                length[i][j] = length[i-1][j-1] + 1;

            // High-Case 2: No Empty-String && 最后一个字母不同 -> 退化成求解两个相同的子问题
            else
                length[i][j] = max(length[i-1][j], length[i][j-1]);
        }

    // Print the Longest Common Subsequence
    stack<char> seq;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            seq.push(X[i-1]);
            i--, j--;
        }

        else if (length[i-1][j] > length[i][j-1])
            i--;
        else
            j--;
    }

    cout << "The LCS = ";
    while (!seq.empty())
    {
        cout << seq.top();
        seq.pop();
    }
    cout << " | length = " << length[m][n] << endl;
}

#endif //TEN_EIGHT_ALGORITHM_3_1_LONGESTCOMMONSUBSEQUENCE_H
