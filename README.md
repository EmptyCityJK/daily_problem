### [小红的陡峭值(四)](https://ac.nowcoder.com/acm/contest/103152/E)
`树形dp`
```c++
dp[i] 以i为根节点的val(陡峭值)
fa[i] i的父节点
状态转移(u是v的父节点)：
dp[u] += dp[v] + abs(u - v)
```
### [活动](https://ac.nowcoder.com/acm/contest/92687/A)
`dp + 组合数`
```C++
dp[i] i个人的方案数
// 从前i-1个人选1个来跟新人斗兽棋
dp[i] = C(i-1, 1) * dp[i - 2];
// 从前i-1个人选2个来跟新人斗地主
dp[i] += C(i-1, 2) * dp[i - 3];
// 从前i-1个人选3个人来跟新人打麻将
dp[i] += C(i-1, 3) * dp[i - 4];
```
### [迷宫问题](https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?channelPut=w25springcamp)
`典题-dfs`
```C++
    res.push_back({xx, yy});
    vis[xx][yy] = 1;
    dfs(xx, yy, res);
    if(flg) return ;
    res.pop_back();
    vis[xx][yy] = 0;
```
### [异或和之和](https://www.luogu.com.cn/problem/P9236)
`Xor`
```C++
求[l,r]的异或和: pre[r] ^ pre[l-1](自反性：a^b^b = a)
求所有[l,r]的子段的异或和之和 => 求两两异或前缀和的异或和(0 和 1搭配才能有贡献)
for(int k=0; k<=20; k++) { // 针对二进制每一位的贡献值
    for(int i=1; i<=n; i++) { // 遍历每个数
        if(a[i] >> k & 1) { // a[i]的第k位是不是1
            ...
        }
    }
}
```
### [密码截取](https://www.nowcoder.com/practice/3cd4621963e8454594f00199f4536bb1?channelPut=w25springcamp)
`求最长回文子串`--枚举回文中心/马拉车