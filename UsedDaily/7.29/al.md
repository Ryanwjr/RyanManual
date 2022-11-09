# 729L2

BF 算法，即暴力(Brute Force)算法，**是普通的模式匹配算法**，BF 算法的思想就是将目标串 S 的第一个字符与模式串 T 的第一个字符进行匹配，若相等，则继续比较 S 的第二个字符和 T 的第二个字符；若不相等，则比较 S 的第二个字符和 T 的第一个字符，依次比较下去，直到得出最后的匹配结果。 BF 算法是一种蛮力算法。

---

• Algorithms can be classified by solution type: • Exact • Approximate • Heuristic

Correctness and efficiency

---

！动态规划经典--this week

背包问题（Knapsack problem）是**一种组合优化的 NP 完全问题**。 问题可以描述为：给定一组物品，每种物品都有自己的重量和价格，在限定的总重量内，我们如何选择，才能使得物品的总价格最高。 问题的名称来源于如何选择最合适的物品放置于给定背包中，背包的空间有限，但我们需要最大化背包内所装物品的价值。

---

$$
\sum_{i=1}^{n}i
$$

LateX \_ ^

---

$$
P_n => P_{n+1} 递归推导
$$

---

```swift
//Uses a recursive binary search function to search for givenCity in the array, and prints out:

//Uses a recursive binary search function to search for givenCity in the array, and prints out:
```

---

```cpp
int fib(int n)
{
if(n==0) return 0;
if(n==1) return 1;
return fib(n-1) + fib(n-2);
}

int main()
{
int n, ans;
printf("Enter a number:\n");
scanf("%d", &n);
if(DEBUG)
printf("%d\n",n);
ans = fib(n);
printf("Fibonacci of %d is %d\n", n, ans);
}
```

这个复杂度是 2^n 因为每一次分出去两个

![image.png](https://res.craft.do/user/full/f7a3cbe9-8926-40c6-8025-3f2d12a743e8/doc/bf02a066-95c8-4410-9b52-f50f62c9a5f7/5e8bea11-6205-4b0d-bcc1-f6e24268c78b)

---

```cpp
//优化 只存3步
int fib(int n)
{
int result = 0;
int preOldResult = 1;
int oldResult = 1;
if(n <= 0) return 0;
if(n > 0 && n < 3) return 1;
for( int i = 3; i <= n; i++ ){
result = preOldResult + oldResult;
preOldResult = oldResult; //Keeping last 2 results
oldResult = result;
}
return result;
}
```
