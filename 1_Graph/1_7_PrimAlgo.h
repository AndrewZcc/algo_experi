/**
 * Prim Algorithm: Minimum Spanning Tree (MST) 最小生成树算法  {Prim Algorithm: 着重-选点}
 * 算法思想: 两个不相交的子集 (one contains the vertices included in MST, other contains the rest vertices.)
 *          每次 Pick the vertex u (has minimum key-value) to mstSet.
 *          然后 Update key-value of all adjacent vertices of u.
 *          Until all vertices are included into the mstSet.
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_7_PRIMALGO_H
#define TEN_EIGHT_ALGORITHM_1_7_PRIMALGO_H

#include "preDefineValue.h"

#define VPrim 5

int minKey(int* key, bool* mstSet)
{
    int min = INF, vertex;

    for (int i=0; i<VPrim; i++)
    {
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            vertex = i;
        }
    }

    return vertex;
}

void printMSTPA(int* parent, int graph[][VPrim])
{
    cout << "The Results of Prim-Algo:" << endl;
    printf("Edge   Weight\n");
    for (int i = 1; i < VPrim; i++)
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
}

void PrimAlgo(int graph[][VPrim])
{
    int parent[VPrim];  // 记录路径信息
    int key[VPrim];     // 记录每个顶点的权重值
    bool mstSet[VPrim]; // 记录每个顶点是否已经被放进了MST

    // 初始化
    for (int i=0; i<VPrim; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    // 循环 V-1次, 每次选出 最小权重 顶点
    for (int count = 0; count < VPrim-1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v=0; v<VPrim; v++)
        {
            if (graph[u][v] != 0 && mstSet[v] != true && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printMSTPA(parent, graph);
}

#endif //TEN_EIGHT_ALGORITHM_1_6_PRIMALGO_H
