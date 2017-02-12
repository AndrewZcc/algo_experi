/*
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_3_COMPARESTRINGS_H
#define TEN_EIGHT_ALGORITHM_2_3_COMPARESTRINGS_H

#include <iostream>

using namespace std;

struct charNode{
    char data;
    charNode* next;
    charNode(char c){data = c; next = NULL;}
};

void insertString(charNode** head, string str)
{
    charNode* temp = *head;

    if (temp == NULL) {
        cout << "insert String: Case-1" << endl;
        *head = new charNode(str[0]);
        temp = *head;
        for (int i=1; i<str.length(); i++)
        {
            temp->next = new charNode(str[i]);
            temp = temp->next;
        }
    } else {
        // Case-2: 插入链表中
        while (temp->next != NULL)
            temp = temp->next;

        for (int i=0; i<str.length(); i++)
        {
            temp->next = new charNode(str[i]);
            temp = temp->next;
        }
    }
}

void printLinkedList(charNode* head)
{
    cout << "The char-Linked-List is: [ ";

    charNode* i = head;
    while (i != NULL)
    {
        cout << i->data << " ";
        i = i->next;
    }
    cout << "]" << endl;
}

int compare(charNode* strList1, charNode* strList2)
{
    // 当 两者前缀 相同时, 就同时 向后移
    while (strList1 && strList2 &&
           strList1->data == strList2->data)
    {
        strList1 = strList1->next;
        strList2 = strList2->next;
    }

    // 移到 两个字符串字符不同的位置, 比较这两个字符的大小即可!
    if (strList1 && strList2) {
        return (strList1->data > strList2->data) ? 1 : -1;
    }
    // 如果一个 字符串是另一个的子字符串, 则较长的那个字符串的 值 将更大!
    if (strList1 && strList2 == NULL) return 1;
    if (strList2 && strList1 == NULL) return -1;

    // 如果两者 长度相同且字符都相同 则返回相等
    return 0;
}

#endif //TEN_EIGHT_ALGORITHM_2_3_COMPARESTRINGS_H
