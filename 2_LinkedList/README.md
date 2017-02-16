## Linked List Algorithm Conclusions

### 学会使用 C++ STL

1. `<set>`
2. `<stack>`
3. `<queue> 等`

### 注意事项
1. 指针定义

	```
	Node* prev, post; 		// 等价于：Node *prev, post; 
							// 等价于：Node *prev; Node post;
	真正正确的定义应该是：
	Node *prev, *post;		// 这样 prev 和 post 两者才都是指针！
	```

2. C++ `随机数`

	```
	int rand(void)			// 伪随机数发生器 [如果种子值相同，每次执行它所产生的伪随机数字序列也会相同]
	void srand(unsigned int seed) // 初始化随机数发生器，为 rand()设置seed值！
	```
	注意：
	- 如果不用srand(int)进行初始化，rand()会默认将其设置为 1, 每次执行时都是 seed = 1，这样其实每次执行所产生的 rand()随机数序列 是相同的；
	- 所以为了让 rand()每次产生的随机数序列不同，到达真正随机的效果！必须调用 srand(int seed)函数来为 rand()的种子(seed)赋值，而且每次赋予seed的值还必须不同(否则就没有意义了)！
	
	所以为了达到真正随机的效果，通常使用如下语句：
	
	```
	srand(time(NULL));		// 用系统时间作为每次执行的 seeds，从而确保了种子的不同。
	rand();					// 因种子的不同，确保了每次执行时 会产生不同的随机数序列!
	```
	
## 
> 引申：蓄水池抽样 (reservior sampling)

* 问题描述：
	- 从不确定的 N 个元素中 随机抽取出 k 个元素出来！
	- 要求 等概率 的抽取！
* 解决方案：
	- `蓄水池抽样 (reservior sampling)`: 保持一个大小为 k 的集合作为蓄水池！依次遍历所有数据的时候以 一定概率( k / i ) 替换这个蓄水池中样本数据！
* 伪代码：
	
	```
	Init : a reservior with size = k
	
	for i = k+1 to N
		int random = rand() % i; 	// 产生一个处于[0, i-1]区间内的随机数
		if (random < k)				// 代表落在了蓄水池内，代表被抽中了！
			swap(reservior[random], i-th element); // 第 i 个元素被选中了，交换进入蓄水池内
	end for
	
	Output : the reservior! (k samples)
	```
* 算法特点分析
	- 时间复杂度很低：`O(N)`
	- 事先不需要知道 N 的确切个数，非常适用于大数据流的情形！

## 
	
