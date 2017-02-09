/**
 * Kruskal Algorithm: Minimum Spanning Tree 最小生成树算法     {Kruskal Algorithm: 着重-选边}
 * 背景知识: 最小生成树 一定有(V-1)条边!
 * MST is a spanning tree with weight less than or equal to the weight of every other spanning tree.
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_6_KRUSKALALGO_H
#define TEN_EIGHT_ALGORITHM_1_6_KRUSKALALGO_H

/**
 * Kruskal 算法思想: 将边排序, 每次选取权重最小的边, 如果该边没有形成环则保留, 如果形成了环则丢弃!
 *                  直到 选出了(V-1)条边 算法结束! MST-生成完成。
 */

/**
 * 定义 数据结构(Graph) 用于存储: 图 (加权无向图)
 */
struct Edge {
    int src, dest;
    int weight;
};
struct GraphKA {
    int VN, E;
    Edge* edge;
};

GraphKA* createGraphKA(int vn, int e)
{
    GraphKA* graph = new GraphKA[sizeof(GraphKA)];

    graph->VN = vn;
    graph->E = e;
    graph->edge = new Edge[e * sizeof(Edge)];

    return graph;
}
void printEdge(int number, Edge e)
{
    cout << "e" << number << ": " << e.src << " ---- " << e.weight
         << " ---- " << e.dest << endl;
}
void printGraphKA(GraphKA* graph)
{
    cout << "Print Graph = " << endl;
    for (int i=0; i<graph->E; i++)
    {
        printEdge(i, graph->edge[i]);
    }
    cout << endl;
}

/**
 * UnionFind Algorithm: 用于检测是否形成 环路
 */
// 将各个顶点分成 V 个子集, 定义 subset 来存储这些子集
struct subset{
    int parent, rank;
};
// 找出 顶点 i 所属的子集 (每个不同的子集用 树根 来区分)
int find(subset* subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
// 合并 两个不同子集
void Union(subset* subsets, int x, int y)
{
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);
    if (xRoot == yRoot) return;

    // 两个不同子树 根据树高(rank) 进行路径压缩
    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

/**
 * 定义比较函数 用于对 图中所有的边 进行排序
 * STL: void sort(T first, T last, bool CompareFunc)
 */
bool compareEdge(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void KruskalAlgo(GraphKA* graph)
{
    printGraphKA(graph);
    Edge results[graph->VN];

    // STEP-1: 对图中 所有的边 按照权重进行排序
    sort(graph->edge, graph->edge + graph->E, compareEdge);
    cout << "After Sort, "; printGraphKA(graph);

    // STEP-2: 逐一选取最短边, 只要不形成回路就保留, 一旦形成回路则抛弃, 直到选出 V-1 条边为止
    //         使用 并查集 检测回路
    // 2.1 将各个顶点分成 VN 个子集, 每个子集一开始初始化为相互独立!
    subset* subsets = new subset[graph->VN * sizeof(subset)];
    for (int v=0; v < graph->VN; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0, i=0;
    while (e < graph->VN-1)     // 从第0条边开始选, 一直选出 V-1 条边 结束
    {
        Edge selectEdge = graph->edge[i++];

        int srcRoot = find(subsets, selectEdge.src);
        int destRoot = find(subsets, selectEdge.dest);

        if (srcRoot != destRoot)    // 代表 selectEdge 这条边 没有形成回路
        {
            results[e++] = selectEdge;
            Union(subsets, srcRoot, destRoot);
        } else {
            // srcRoot = destRoot 代表这条边的两个顶点, 本身已处于同一个子集内
            // 如果加入这条边, 就会形成回路! 所以这里应该将 这条边 直接抛弃!
        }
    }

    // Print Results: the edge-set of MST.
    cout << "The Results of Kruskal-Algo:"<< endl;
    for (i=0; i<e; i++) printEdge(i, results[i]);
}

#endif //TEN_EIGHT_ALGORITHM_1_6_KRUSKALALGO_H
