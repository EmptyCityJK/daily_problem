### lower_bound/upper_bound
在C++中，lower_bound和upper_bound是用于在有序序列中高效查找元素的函数，位于头文件。它们的时间复杂度为O(log n)（要求随机访问迭代器）。

一般来说，这两个函数能实现的功能，使用二分法都能实现；不过为了编码速度和代码的简洁性，在程序的某个环节如果需要一个简单二分查找了，我们往往还是使用这两个函数来查找。

#### 功能简要说明
lower_bound：返回第一个`不小于value`的元素的位置
upper_bound：返回第一个`大于value`的元素的位置

#### 函数原型
```cpp
template< class ForwardIt, class T >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );

template< class ForwardIt, class T >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );

// 带自定义比较函数的版本
template< class ForwardIt, class T, class Compare >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );

template< class ForwardIt, class T, class Compare >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
```

#### 详细用法
> 首先使用这两个函数的一个前提条件是：**有序**。
> 如果是对于`数组`使用，需要先保证数组是有序的；
> 如果对于`集合`使用，需要确保是set，而不是unordered_set，因为set是默认有序的。
`pre()`: 获取上一个位置
```cpp
// 找边界值的下标
lower_bound(a.begin(), a.end(), value) - a.begin() // >=vaule
prev(upper_bound(a.begin(), a.end(), value)) - a.begin() // <=vaule
upper_bound(a.begin(), a.end(), value) - a.begin() // >vaule
prev(lower_bound(a.begin(), a.end(), value)) - a.begin() // <vaule
```
如果是需要获取对应位置上的值，用一个*获取地址上的值即可
```cpp
int t = *lower_bound(a.begin(), a.end(), value);
```

找不到的时候：

lower_bound()和upper_bound()都是**返回数组的最后一个元素后面一个位置**。
```CPP
if(lower_bound(a.begin(), a.end(), value) == a.end())
    cout << "没有找到第一个>=value的位置";
```

---

针对`set`，set没有位置（下标）的区分，一般来说都是查找值，具体用法如下：
```cpp
set<int> st = {5, 1, 9, 3, 0};
// 找到>=2的最小数, 输出3
cout << *st.lower_bound(2) << endl;
// 找不到的时候返回st.end(), 输出1, 表示true
cout << (st.lower_bound(10) == st.end()) << endl;
```
#### 案例学习(几种特殊边界情况)
找<=的右边界：
```cpp
// 注意数组下标从0开始
vector<int> a = {0, 1, 2, 3, 4, 5};
// 找<=6的最后一个数的位置
int res = prev(upper_bound(a.begin(), a.end(), 6)) - a.begin();
// res = 5
cout << res << endl;

// 找<=5的最后一个数的位置
res = prev(upper_bound(a.begin(), a.end(), 5)) - a.begin();
// res = 5
cout << res << endl;

// 找<=-1的最后一个数的位置
res = prev(upper_bound(a.begin(), a.end(), -1)) - a.begin();
// 找不到，此时的prev(upper_bound(a.begin(), a.end(), -1))其实是会返回a.begin()的前一个位置
// res = -1
cout << res << endl;
```
找>=的左边界
```cpp
// 注意数组下标从0开始
vector<int> a = {0, 1, 2, 3, 4, 5};
// 找>=6的第一个数的位置
int res = lower_bound(a.begin(), a.end(), 6) - a.begin();
// 找不到，此时lower_bound返回的是a.end()，5后面一个位置
// res = 6
cout << res << endl;
// 输出 0
cout << lower_bound(a.begin(), a.end(), 6) - a.end() << endl;
```