## Dynamic Programming Conclusions

### 相关概念

1. 动态规划 = 初始状态(状态) + 递推公式(状态转移方程)；
	- 状态：用于定义 该问题 的子问题；
	- 状态转移方程：用于定义 该问题与其子问题 之间的关系！
	- 总思想：`欲求解一个问题的解，先去求解该问题的子问题的解`！
	
	> Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again.

2. 适合使用动态规划进行求解的问题具有两大特征：`Overlapping/Common Subproblems` 和 `Optimal Substructure`。