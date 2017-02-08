#include <iostream>
#include "1_Graph/1_1_graph_bfs.h"
#include "1_Graph/1_2_graph_dfs.h"
#include "1_Graph/1_3_DijistraAlgo.h"
#include "1_Graph/1_4_FloydAlgo.h"
#include "1_Graph/1_5_UnionFind.h"

using namespace std;

/**
 * 学习资料链接: http://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/
 */

int main() {

    /*
    cout << "BFS and DFS Algorithm" << endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    // BFS and DFS
    g.printGraph();
    g.BFS(2);
    g.BFS(3);
    cout << endl;
    g.DFS(2);
    g.DFS(3);

    cout << endl << "Dijistra's Shortest Path Algorithm" << endl;
    int graph[][9] = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    dijistra(graph, 0);

    cout << endl << "Floyd's All Pairs Shortest Path Algorithm" << endl;
    int graph[][4] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
    };
    floydAlgo(graph);
    */

    cout << endl << "UnionFind Algorithm: Detect Equality of entries / Cycle in Graph." << endl;

    UnionFind uf(10);
    uf.printUF();
    cout << "Number of connections: " << uf.getCount() << endl;
    uf.Union(4, 3);
    uf.printUF();
    cout << "Number of connections: " << uf.getCount() << endl;
    uf.isConnected(3, 6) ? cout << "3 yes 6\n" : cout << "3 no 6\n";
    uf.isConnected(3, 4) ? cout << "3 yes 4\n" : cout << "3 no 4\n";
    uf.Union(4, 6);
    uf.printUF();
    cout << "Number of connections: " << uf.getCount() << endl;
    uf.isConnected(3, 6) ? cout << "3 yes 6\n" : cout << "3 no 6\n";
    uf.isConnected(3, 4) ? cout << "3 yes 4\n" : cout << "3 no 4\n";
    uf.Union(8, 9);
    uf.printUF();
    cout << "Number of connections: " << uf.getCount() << endl;
    uf.isConnected(8, 9) ? cout << "8 yes 9\n" : cout << "8 no 9\n";
    uf.isConnected(8, 6) ? cout << "8 yes 6\n" : cout << "8 no 6\n";

    cout << endl << uf.Find(4) << " " << uf.Find(8) << endl;

    return 0;
}