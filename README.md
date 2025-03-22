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
### [计算字符串的编辑距离](https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?channelPut=w25springcamp)
`dp -- 编辑距离问题`
我的误区：试图模拟删除/插入操作
Tips: We can consider **insert** as **delete**.
```C++
// dp[i][j]: a[0~i-1] 和 b[0~j-1]之间的编辑距离（最小操作次数：插入 删除 改变）
// 无操作
if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
else {
    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1; //删除a，删除b
    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1); //更改
}
dp[n][m] -> ans
```
### [字符串通配符](https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?channelPut=w25springcamp)
`dp＋字符串 -- 类编辑距离`
```C++
// dp[i][j]: s[0-i-1] 和 p[0-j-1] 之间能否匹配
vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
// 初始化
dp[0][0] = true;
// p为空串时，只有s全为*才为true
for(int i=0; i<n; i++) {
    if(s[i] != '*') break;
    dp[i + 1][0] = true;
}
// 状态转移
// *: 1.插入第>=2个 2.不插入 3.插入第1个
if(s[i-1] == '*' && check(p[j-1])) dp[i][j] = dp[i][j-1] | dp[i-1][j] | dp[i-1][j-1];
// ?: 替换(与dp[i-1][j-1]状态一样)
else if(s[i-1] == '?' && check(p[j-1])) dp[i][j] = dp[i-1][j-1];
// 相等情况
else if(tolower(s[i-1]) == tolower(p[j-1])) dp[i][j] = dp[i-1][j-1]; 
```