## Linked List Algorithm Conclusions

### 学会使用 C++ STL

1. `<set>`
2. `<stack>`
3. `<queue> 等`

### 注意事项
1. 指针定义

```
Node* prev, post; 	// 等价于：Node *prev, post; 
					// 等价于：Node *prev; Node post;
真正正确的定义应该是：
Node *prev, *post;	// 这样 prev 和 post 两者才都是指针！
```
