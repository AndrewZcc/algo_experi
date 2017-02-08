/**
 * 并查集算法 Union-Find Algorithm: Detect Cycle in an Undirected Graph
 * Created by zhchuch.
 */

#ifndef TEN_EIGHT_ALGORITHM_1_5_UNIONFIND_H
#define TEN_EIGHT_ALGORITHM_1_5_UNIONFIND_H

class UnionFind {
private:
    int* id;        // 将 不同元素 划分成为 不同的组
    int size;
    int count;      // 记录 连通分量的个数
public:
    UnionFind(int N)
    {
        size = count = N;
        id = new int[N];
        for (int i=0; i<N; i++) id[i] = i;
    }

    int getCount(){return count;}

    bool isConnected(int p, int q) {
        return Find(p) == Find(q);
    }

    int Find(int p)
    {
        while (id[p] != p) p = id[p];

        return p;
    }

    void Union(int p, int q)
    {
        cout << "union(" << p << ", " << q << ")" << endl;
        // if (isConnected(p, q)) return;

        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot == qRoot) return;

        // 方法一: 使用循环修改                        O(n)
        /*
        for (int i=0; i<size; i++)
            if (id[i] == id[p])
                id[i] = id[q];
         */

        // 方法二: 使用 根树 的概念, 直接修改根的指向     O(1)
        // p 所属的等价树的树根为 Find(p), q 所属的等价树的树根为 Find(q).
        id[pRoot] = qRoot;

        count--;
    }

    void printUF()
    {
        for (int i=0; i<size; i++)
            cout << id[i] << " ";
        cout << endl;
    }
};

#endif //TEN_EIGHT_ALGORITHM_1_5_UNIONFIND_H
