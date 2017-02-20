## Sorting & Searching Algo. Conclusions

> · 可参考 [algorithm_geeks_cpp](https://github.com/AndrewZcc/algorithm_geeks_cpp)
>
> · [各种排序算法 对比分析与总结](https://github.com/AndrewZcc/algorithm_geeks_cpp/blob/master/sort/summary.md)

注意：  

1. 在运用到 递归算法 的时候，一定要注意确定好 边界！

	```
	int recurMethod(int* arr, int l, int h)
	{
		if (condition) {
			***
			swap(arr[l+offset], arr[pivot]);
			recurMethod(arr, l+offset, h);
		}
		// 递归终止条件
		return -1;
	}
	```

2. 基于 `有序数列` 上的查找，基本从 查找效率角度 考虑都是 二分查找的变体 (The Variant of Binary Search)！