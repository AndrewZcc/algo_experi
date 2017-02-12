/**
 * Insert the entry into a sorted linked list
 *
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_2_1_INSERTIONSORTEDLIST_H
#define TEN_EIGHT_ALGORITHM_2_1_INSERTIONSORTEDLIST_H

/** 分为以下几种情况:
 * Case-1. 插入空链表
 * Case-2. 插入链表头
 * Case-3. 正常插入
 */
struct Node {
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

/**
 * 注意这里由于要将函数修改的结果, 继续保留到head链表中, 所以采用的是 指针传参!
 */
void insertNode(Node** head, int n)
{
    // Case-1: NULL list
    if (*head == NULL) {
        cout << "Case-1" << endl;
        *head = new Node(n);
    }
    else {
        Node* i = *head;
        Node* j = *head;

        // 使用 滑动窗口(i, j) 来确定插入位置
        while (j != NULL)
        {
            if (j->data >= n) break;
            i = j;
            j = j->next;
        }

        // Case-2: 插入在链表头
        if (j == *head)
        {
            cout << "Case-2" << endl;
            *head = new Node(n);
            (*head)->next = j;
        }
        else // Case-3: 正常插入链表
        {
            cout << "Case-3" << endl;
            Node* temp = new Node(n);
            i->next = temp;
            temp->next = j;
        }
    }
}

void printLinkedList(Node* head)
{
    cout << "The Linked-List is: [ ";

    Node* i = head;
    while (i != NULL)
    {
        cout << i->data << " ";
        i = i->next;
    }

    cout << "]" << endl;
}

#endif //TEN_EIGHT_ALGORITHM_2_1_INSERTIONSORTEDLIST_H
