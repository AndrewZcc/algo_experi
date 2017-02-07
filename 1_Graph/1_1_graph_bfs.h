/**
 * BFS Algorithm: Breath First Traversal for a Graph
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_GRAPH_BFS_H
#define TEN_EIGHT_ALGORITHM_GRAPH_BFS_H

#include <iostream>
#include <list>

using namespace std;

/**
 * BFS Algorithm: Breath First Traversal for a Graph
 */
class Graph
{
private:
    int V;              // 图中 节点个数
    list<int> *adj;     // 图中 每个节点的相邻节点链表 [图表示法: 邻接链表法]
public:
    Graph(int v)
    {
        V = v;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void BFS(int start);
    void DFS(int start);
    friend void DFSHelper(Graph g, int start, bool *visited);   // 申明 友元函数, 使其可使用私有成员变量
    void printGraph();
};

void Graph::BFS(int s)
{
    cout << "BFS("<<s<<"): " << endl;

    bool *visited = new bool[V];
    list<int> queue;

    // 初始化 方法一: for-循环法
    for (int i=0; i<V; i++)
        visited[i] = false;

    // 初始化 方法二: memset-内存地址填充法
    //memset(visited, 0, V);

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        int cur = queue.front();
        cout << cur << " ";
        queue.pop_front();

        for (list<int>::iterator i = adj[cur].begin(); i != adj[cur].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    cout << endl;
}

void Graph::printGraph()
{
    cout << "The adjacent list representation of Graph:" << endl;
    for (int i=0; i<V; i++)
    {
        cout << i << " | ";
        for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;
}

#endif //TEN_EIGHT_ALGORITHM_GRAPH_BFS_H
