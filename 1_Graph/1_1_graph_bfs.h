/**
 * BFS Algorithm: Breath First Traversal for a Graph
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_GRAPH_BFS_H
#define TEN_EIGHT_ALGORITHM_GRAPH_BFS_H

#include <iostream>
#include <list>
#include <stack>

using namespace std;

/**
 * BFS Algorithm: Breath First Traversal for a Graph
 */
class Graph
{
private:
    int VG;              // 图中 节点个数
    list<int> *adj;     // 图中 每个节点的相邻节点链表 [图表示法: 邻接链表法]
public:
    Graph(int v)
    {
        VG = v;
        adj = new list<int>[VG];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int start);

    void DFS(int start);
    friend void DFSHelper(Graph g, int start, bool *visited);   // 申明 友元函数, 使其可使用私有成员变量

    void topologicalSort(); // topo-sort aim to DAG-graph.
    friend void topSortHelper(Graph g, stack<int>& s, int vertex, bool* visited);

    void printGraph();
};

void Graph::BFS(int s)
{
    cout << "BFS("<<s<<"): " << endl;

    bool *visited = new bool[VG];
    list<int> queue;

    // 初始化 方法一: for-循环法
    for (int i=0; i<VG; i++)
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
    for (int i=0; i<VG; i++)
    {
        cout << i << " | ";
        for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;
}

#endif //TEN_EIGHT_ALGORITHM_GRAPH_BFS_H
