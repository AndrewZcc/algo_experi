/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_3_3_EDITDISTANCE_H
#define TEN_EIGHT_ALGORITHM_3_3_EDITDISTANCE_H

#include <iostream>

using namespace std;

int min2(int x, int y, int z)
{
    return min(min(x, y), z);
}
// Method-1: Naive Recursive Method
int editDistance(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    if (m == 0) {
        //cout << "Insert " << n << "times!" << endl;
        return n;
    }
    if (n == 0) {
        //cout << "Delete " << m << "times!" << endl;
        return m;
    }

    // Case1: 最后一个字符相同
    if (str1[m-1] == str2[n-1])
        return editDistance(str1.erase(m-1), str2.erase(n-1));

    // Case2: 最后一个字符不同 (三种操作取最小)
    return 1 + min2(
            editDistance(str1, str2.erase(n-1)),  // Insert
            editDistance(str1.erase(m-1), str2),  // Delete
            editDistance(str1.erase(m-1), str2.erase(n-1)) // Replace
    );
}

// Method-2: Dynamic Programming: 用数组将重复计算的 重叠子问题 的计算结果存储起来
int editDistanceDP(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];   // 将每次 重叠子问题 的计算结果都存储在这个数组中!
                        // 从而 减少了递归反复求解重叠子问题的次数!

    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + min2(dp[i][j-1],    // Case-1: Insert
                                    dp[i-1][j],    // Case-2: Delete
                                    dp[i-1][j-1]); // Case-3: Replace
        }

    return dp[m][n];
}

#endif //TEN_EIGHT_ALGORITHM_3_3_EDITDISTANCE_H
