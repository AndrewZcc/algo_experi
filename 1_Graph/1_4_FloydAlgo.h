/**
 * [多源最短路径问题] Floyd's Algorithm: solving the All Pairs Shortest Path Problem.
 * Created by zhchuch.
 *
 * 时间复杂度: O(n^3), 空间复杂度: O(n^2)
 */

#ifndef TEN_EIGHT_ALGORITHM_1_4_FLOYDALGO_H_H
#define TEN_EIGHT_ALGORITHM_1_4_FLOYDALGO_H_H

#include <iostream>
#include "preDefineValue.h"
using namespace std;

void floydAlgo(int graph[][V])
{
    int dist[V][V];         // 记录距离信息
    int i, j, k;

    for (i=0; i<V; i++)     // 初始化距离信息为 初始图
        for (j=0; j<V; j++)
            dist[i][j] = graph[i][j];

    for (k=0; k<V; k++)     // all vertices one by one as the intermediate vertex.
    {
        for (i=0; i<V; i++)         // For every source
        {
            for (j=0; j<V; j++)     // For every destination
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (i=0; i<V; i++) {
        for (j = 0; j < V; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

#endif //TEN_EIGHT_ALGORITHM_1_4_FLOYDALGO_H_H
