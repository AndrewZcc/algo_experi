/**
 * Topological Sorting: 拓扑排序 注意:只针对 DAG-图 (Directed Acyclic Graph, 有向无环图)
 * 注意: Topological Sorting for a graph is not possible if the graph is not a DAG!
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_8_TOPOLOGICALSORT_H
#define TEN_EIGHT_ALGORITHM_1_8_TOPOLOGICALSORT_H

#include "1_1_graph_bfs.h"

/**
 * Input: A DAG graph
 * Output: a linear ordering of its vertices
 * 特点: The first vertex in topo-sorting is always a vertex with in-degree as 0 (no in-coming edges)
 */

// we can modify DFS to find Topological-Sorting of a graph [not print the DFS rather than push into a stack.]
void topSortHelper(Graph graph, stack<int>& s, int vertex, bool* visited)
{
    visited[vertex] = true;

    list<int>::iterator iter;
    for (iter = graph.adj[vertex].begin(); iter != graph.adj[vertex].end(); iter++)
        if (!visited[*iter])
            topSortHelper(graph, s, *iter, visited);

    s.push(vertex);
}

void Graph::topologicalSort()
{
    stack<int> s;                   // 用于记录图中的顶点
    bool* visited = new bool[VG];
    memset(visited, 0, VG);

    // for each vertex i
    for (int i=0; i<VG; i++)
        if (visited[i] == false)
            topSortHelper(*this, s, i, visited);

    // Print the results of top-sort
    cout << "the topological sorting results:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

#endif //TEN_EIGHT_ALGORITHM_1_8_TOPOLOGICALSORT_H
