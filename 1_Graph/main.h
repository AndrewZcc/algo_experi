#include <iostream>
#include "1_1_graph_bfs.h"
#include "1_2_graph_dfs.h"
#include "1_3_DijistraAlgo.h"
#include "1_4_FloydAlgo.h"
#include "1_5_UnionFind.h"
#include "1_6_KruskalAlgo.h"
#include "1_7_PrimAlgo.h"
#include "1_8_TopologicalSort.h"
#include "1_9_Apply_FindWords.h"
#include "1_10_Apply_FindBridges.h"

using namespace std;

/**
 * ----------------------------
 * --- Graph Algorithm Test ---
 * ----------------------------
 */
void main_1_Graph() {
    /*
    // 1-1, 1-2
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

    // 1-3
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

    // 1-4
    cout << endl << "Floyd's All Pairs Shortest Path Algorithm" << endl;
    int graph[][4] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
    };
    floydAlgo(graph);

    // 1-5
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

    // 1-6
    cout << endl << "Kruskal Algorithm: Minimum Spanning Tree Algorithm" << endl;
    GraphKA* graph = createGraphKA(4, 5);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalAlgo(graph);

    // 1-7
    cout << endl << "Prim Algorithm: Minimum Spanning Tree Algorithm (2)" << endl;
    int graphPA[][5] = {    // represent the graph using adjacency-matrix!
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
    };

    PrimAlgo(graphPA);

    // 1-8
    cout << endl << "Topological Sorting of the given DAG graph \n";
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.printGraph();
    g.topologicalSort();

    // 1-9
    cout << endl << "Application-1: Find all possible words in a given dictionary! " << endl;
    char charBoard[][3] = {
            {'G', 'I', 'Z'},
            {'U', 'E', 'K'},
            {'Q', 'S', 'E'}
    };
    cout << "Results: Following words in dictionary are present:\n";
    findWords(charBoard);
    */

    // 1-10
    cout << endl << "Application-2: Find all bridges in a given undirected graph!" << endl;
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.printGraph();
    //g1.bridge();
    g1.allBridges();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.printGraph();
    //g2.bridge();
    g2.allBridges();

    Graph g(3);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.printGraph();
    cout << "num of connects: " << numConnectedParts(g) << endl;

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.printGraph();
    //g3.bridge();
    g3.allBridges();

}