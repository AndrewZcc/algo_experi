## Graph Algorithm Conclusions

### 1. 图的表示法
- 邻接链表法
- 邻接矩阵法
- 自定义图结构法 Graph = <V, E>

### 2. 基于 图 的算法
大多数都需要用到如下几个临时变量：

```
int dist[V]; 		// 用于 记录图中各顶点到源点的距离信息
int parent[V];		// 用于 记录图中各顶点 的 父节点信息，或者并查集中的归属问题
bool isVisted[V];	// 用于 判断图中各个顶点 有没有被访问过
```

### 3. 编程中的注意事项：

3.1 在进行 比较或赋值 时, 等号右边的 右值 一定要是常量,不能使用变量,否则很可能会导致运行逻辑错误！

3.2 C++ int2string 方法（利用 \<sstream>库）

```
string int2String(int i) {
	ostringstream ss;
	ss << i;
	string str = ss.str();
	return str;
}
```