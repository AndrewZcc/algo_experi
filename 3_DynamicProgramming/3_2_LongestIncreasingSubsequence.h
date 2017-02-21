/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_3_2_LONGESTINCREASINGSUBSEQUENCE_H
#define TEN_EIGHT_ALGORITHM_3_2_LONGESTINCREASINGSUBSEQUENCE_H

/**
 * Method-1: 两重循环更新 LIS 的长度数组
 * 复杂度: O(N^2)
 */
void LIS(int* arr, int len)
{
    int length[len];

    // 初始化所有节点
    for (int i=0; i<len; i++)
        length[i] = 1;

    // 算法复杂度: O(N^2)
    for (int i=0; i<len; i++)
        for (int j=0; j<i; j++)
            if (arr[j] < arr[i] && (length[j]+1) > length[i]) // 最长递增子序列
                length[i] = length[j]+1;

    // 找出最长的递增子序列
    int max = 0, index = -1;
    for (int i=0; i<len; i++) {
        if (max < length[i]) {
            max = length[i];
            index = i;
        }
    }

    int temp = arr[index];
    stack<int> seq;
    seq.push(temp);
    // 根据长度规则, 找出具体的 最长递增子序列
    for (int l = max-1; l >=1; l--)
        for (int j = 0; j <= index; j++)
            if (length[j] == l && arr[j] < temp) {
                seq.push(arr[j]);
                temp = arr[j];
                index = j;
            }

    cout << "Longest Increasing Subsequence = ";
    while (!seq.empty())
    {
        cout << seq.top() << " ";
        seq.pop();
    }
    cout <<"| length = " << max << endl;
}

/**
 * Method-2: 分情况讨论
 * 复杂度 O(NlogN)
 */
void LISNlgN(int* arr, int len)
{
    // ...
}
#endif //TEN_EIGHT_ALGORITHM_3_2_LONGESTINCREASINGSUBSEQUENCE_H
