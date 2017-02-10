/**
 * Application 2: Find all bridges in a given undirected graph.
 * 思想: 判断一条边是不是 bridge 的方法是: 将它移去,看图的连通分量有没有增加
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_10_FINDBRIDGES_H
#define TEN_EIGHT_ALGORITHM_1_10_FINDBRIDGES_H

#include <sstream>
#include "1_1_graph_bfs.h"

/**
 * 求取一张图上连通分量的数目
 * @param graph
 * @return 连通分量个数
 */
int numConnectedParts(Graph graph)
{
    string str="";

    int parent[graph.VG];
    //bool visited[graph.VG];

    for (int i=0; i<graph.VG; i++)
        parent[i] = i;
    //memset(visited, false, graph.VG);

    for (int i=0; i<graph.VG; i++)
    {
        for (auto iter = graph.adj[i].begin(); iter != graph.adj[i].end(); iter++) // auto = list<int>::iterator
        {
            //for (int k=0; k<graph.VG; k++) cout << parent[k] << " "; cout << endl;

            /**
             * 注意: 在进行 比较和复制 时, 等号右边的 右值 一定要是常量,不能使变量,否则会导致运行逻辑错误
             */
            int a = parent[*iter], b = parent[i];
            if (parent[i] < parent[*iter]) {
                for (int k=0; k<graph.VG; k++)
                    if (parent[k] == a)     // 错误: parent[k] == parent[*iter]
                        parent[k] = b;
            } else {
                for (int k=0; k<graph.VG; k++)
                    if (parent[k] == b)     // 错误: parent[k] == parent[i]
                        parent[k] = a;
            }
        }
    }

    for (int i=0; i<graph.VG; i++) {
        // int2string
        ostringstream ss;
        ss << parent[i];
        string s = ss.str();

        // 判断一个字符串中是否包含另一个字符串
        if (str.find(s) == string::npos)
            str += s;
    }
    //cout << "str = " << str << endl;

    return str.size();
}

void Graph::allBridges()
{
    for (int i=0; i<VG; i++)
    {
        for (auto iter = adj[i].begin(); iter != adj[i].end(); iter++)
        {
            int n1Connect = numConnectedParts(*this);

            cout << "remove edge (" << i << ", " << *iter << ") " << endl;
            Graph temp(*this);
            temp.adj[i].remove(*iter);
            int n2Connect = numConnectedParts(temp);

            cout << "n1Connect = " << n1Connect << ", n2Connect = " << n2Connect << endl;

            // 算法思想: 移除边之后, 看连通分量有没有变多, 多了则代表是 桥!
            if (n2Connect > n1Connect)
                cout << "Bridge: " << i << " --- " << *iter << endl;
        }
    }
}

// ============= ============= ============= ============= =============

/**
 * 原文链接: http://www.geeksforgeeks.org/bridge-in-a-graph/
 * 本算法还有些问题
 */
void findBridgeHelper(Graph g, int vertex, bool* visited, int* disc, int* low, int* parent)
{
    static int time = 0;

    visited[vertex] = true;
    disc[vertex] = low[vertex] = ++time;

    list<int>::iterator iter;
    for (iter = g.adj[vertex].begin(); iter != g.adj[vertex].end(); iter++)
    {
        int v = *iter;

        if (!visited[v])
        {
            parent[v] = vertex;
            findBridgeHelper(g, v, visited, disc, low, parent);

            low[vertex] = min(low[vertex], low[v]);

            if (low[v] > disc[vertex])
                cout << vertex << " --- " << v << endl;
        }
        else if (v != parent[vertex])
        {
            low[vertex] = min(low[vertex], low[v]);
        }
    }
}

void Graph::bridge()
{
    bool* visited = new bool[VG];
    int* disc = new int[VG];
    int* low = new int[VG];
    int* parent = new int[VG];

    memset(parent, -1, VG);
    memset(visited, false, VG);

    for (int i=0; i<VG; i++)
        if (!visited[i])
            findBridgeHelper(*this, i, visited, disc, low, parent);
}

#endif //TEN_EIGHT_ALGORITHM_1_10_FINDBRIDGES_H
