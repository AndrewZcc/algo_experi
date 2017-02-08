/**
 * [单源最短路径问题] Dijistra's Algorithm: find the shortest path from source to all vertices.
 * 处理对象: 一个 无向/有向 加权图 G
 * Created by zhchuch.
 *
 * 时间复杂度: O(n^2)
 */

#ifndef DIJISTRAALGO_H
#define DIJISTRAALGO_H

#include <iostream>
#include "preDefineValue.h"
using namespace std;

// 找到当前所有节点中 已确信拥有最短距离的节点
int minDistance(int* dist, bool* spt)
{
    int minValue = INF, min;

    for (int i=0; i<V; i++)
    {
        if (spt[i]==false && dist[i] <= minValue)
        {
            minValue = dist[i];
            min = i;
        }
    }

    return min;
}

void printPath(int* parent, int point)
{
    if (parent[point] == -1) {
        cout << point;
        return;
    }

    cout << point << "<-";
    printPath(parent, parent[point]);
}

bool isFinished(bool* spt)
{
    for (int i=0; i<V; i++)
        if (spt[i] == false)
            return false;

    return true;
}

/**
 * Dijistra's Algorithm: find the shortest path from source to all vertices.
 * 处理对象: 一个 无向/有向 加权图 G
 */
void dijistra(int graph[V][V], int src)
{
    //cout << "INF = " << INF << endl;
    int dist[V];        // 记录 距离信息
    int parent[V];      // 记录 路径信息
    bool sptSet[V];     // 标记节点是否已访问

    // 运算过程中的辅助空间 初始化
    for (int i=0; i<V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;
    parent[src] = -1;

    // 判断图中所有节点是否都已计算完毕, 没有则继续
    while (!isFinished(sptSet))     // V = 9, 外循环9次 [确保图上所有的节点都被计算到了]
    // 优化方案: for (int count = 0; count < V-1; count++)   // V=9, [0,8) 外循环8次, 可以少循环一次
    {
        // 找到当前 能确定的拥有最短距离的节点
        int curMin = minDistance(dist, sptSet);

        sptSet[curMin] = true;
        // 以此节点为依据, 更新其所有相邻节点的 最短距离数值, 同时记录路径信息
        for (int i=0; i<V; i++)
        {
            if (sptSet[i] == false && graph[curMin][i] != 0 &&
                dist[curMin] != INF && dist[curMin]+graph[curMin][i] < dist[i]) {
                dist[i] = dist[curMin] + graph[curMin][i];      // 更新相邻节点 距离信息
                parent[i] = curMin;     // 记录路径信息
            }
        }
    }

    cout << "The Shortest Distances and Paths:" << endl;
    for (int i=0; i<V; i++)
    {
        cout << i << "\t\t" << dist[i] << "\t\t";
        printPath(parent, i); cout << endl;
    }
}

#endif