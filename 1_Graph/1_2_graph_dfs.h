/**
 * DFS algorithm: Depth First Traversal for a Graph
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_GRAPH_DFS_H
#define TEN_EIGHT_ALGORITHM_GRAPH_DFS_H

#include "1_1_graph_bfs.h"

/**
 * DFS algorithm: Depth First Traversal for a Graph
 */

void DFSHelper(Graph g, int start, bool *visited)
{
    if (!visited[start]) {
        cout << start << " ";
        visited[start] = true;

        for (list<int>::iterator it = g.adj[start].begin(); it != g.adj[start].end(); it++) {
            DFSHelper(g, *it, visited); // 对每一个子分支都不停地向其最深处递归的挺近, depth-first
        }
    }
}

void Graph::DFS(int start)
{
    cout << "DFS("<<start<<"): " << endl;
    bool *visited = new bool[V];

    memset(visited, 0, V);

    DFSHelper(*this, start, visited);

    cout << endl;
}

#endif //TEN_EIGHT_ALGORITHM_GRAPH_DFS_H
