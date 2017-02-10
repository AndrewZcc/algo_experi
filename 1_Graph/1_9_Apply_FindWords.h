/**
 * Application 1: Find all possible words in a board of characters.
 * 思想: 遍历所有可能的string, 然后逐一判断这些string是否合法(是否在给定的词典内)
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_9_FINDWORDS_H
#define TEN_EIGHT_ALGORITHM_1_9_FINDWORDS_H

int M = 3, N = 3;

// Given a dictionary
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int dictSize = sizeof(dictionary)/ sizeof(dictionary[0]);

// 判断一个字符串是否是词典中的单词
// @TEST: string test; while (cin >> test) cout << isWord(test);
bool isWord(string &str)
{
    for (int i=0; i<dictSize; i++)
        if (str == dictionary[i])
            return true;

    return false;
}

/**
 * findWordsHelper() 函数目的: 递归打印所有的字符串
 * 例如: 递归访问所有以 'G'开头 的合法字符串
 *      findWordsHelper(board, visited, 0 , 0, str);
 */
void findWordsHelper(char board[][3], bool visited[3][3], int i, int j, string& str)
{
    visited[i][j] = true;
    str += board[i][j];

    // 判断该字符串是否是单词
    if (isWord(str))
        cout << str << endl;

    for (int row = i-1; row <= i+1 && row < 3; row++) {
        for (int col = j - 1; col <= j + 1 && col < 3; col++) {
            if (row >= 0 && col >= 0 && !visited[row][col])
                findWordsHelper(board, visited, row, col, str);
        }
    }

    // 当一个字符 没有可用的后继字符 时,需要把当前字符从字符串中去除,然后换成下一个字符
    str.erase(str.length()-1);
    // 画龙点睛 之笔: 当 当前字符 没有后继字符时, 把它从字符串末尾删除,同时标记为未访问(false)
    visited[i][j] = false;
}

void findWords(char board[][3])
{
    bool visited[3][3];
    memset(visited, 0, M*N);
    string str = "";

    // For every character, get its all strings begin with it. {DFS}
    // Then determine whether those strings are valid-word or not!
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            findWordsHelper(board, visited, i, j, str);
}

#endif //TEN_EIGHT_ALGORITHM_1_9_FINDWORDS_H
