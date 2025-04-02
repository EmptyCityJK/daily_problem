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
### [小苯的Polygon](https://ac.nowcoder.com/acm/contest/104637/E)
`01背包dp`
**能否构成凸多边形：**最大边 < 其他次小边之和
```C++
// 枚举最大边a[i], 从a[1~i-1]找到满足一个和大于a[i]的组合的最小值
vector<bool> dp(10001, false); // dp[i]: 和为i的组合存在与否
dp[0] = true;
int ans = 1e9;
for(int i=1; i<=n; i++) { // 最大边
    for(int j=a[i]+1; j<=10000; j++) { // 和
        // dp[j]: 使用上一层的结果
        if(dp[j]) {
            ans = min(ans, j + a[i]);
            break;
        }
    }
    for(int j=10000; j>=a[i]; j--) {
        dp[j] = dp[j] | dp[j-a[i]];
    }
}
```
### [图的遍历](https://www.luogu.com.cn/problem/P3916)
`有向图，求 A(v) 表示从点 v 出发，能到达的编号最大的点`
1 -> 5 -> 4 -> 3 -> 2
正难则反：2 -> 3 -> 4 -> 5 -> 1
反向建图，倒着遍历(n~1)
```C++
for(int i=1; i<=m; i++) {
    int u, v; cin >> u >> v;
    g[v].push_back(u); // 反向建边
}
```
1. DFS
```C++
vector<int> ans(n + 1);
function<void(int, int)> dfs = [&](int u, int res) {
    if(ans[u]) return;
    ans[u] = res;
    for(int v: g[u]) {
        dfs(v, res);
    }
};
for(int i=n; i>=1; i--)
    dfs(i, i);
```
2. BFS
```C++
int ans[n + 1];
vector<bool> vis(n + 1);
for(int i=1; i<=n; i++) ans[i] = i;
for(int i=n; i>=1; i--) {
    queue<int> q; q.push(i);
    while(q.size()) {
        int u = q.front(); q.pop(); vis[u] = 1;
        for(int t: g[u]) {
            if(vis[t]) continue;
            vis[t] = 1; q.push(t);
            ans[t] = max(i, ans[t]);
        }
    }
}
```
### [摆花](https://www.luogu.com.cn/problem/P1077)
`多重背包-dp`
> N种物品，容量为V的背包，第i种物品最多有s[i]个，每件物品体积为v[i]，价值为w[i]。
> 求解：将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
```C++
// 状态转移：前i件物品背包装了体积为j的物品，第i件物品的个数为k
dp[i][j] = max(dp[i][j], dp[i-1][j - k*v[i]] + k*w[i]); k = 0~s[i]
```
**对于此题：**n种花，最多可以摆m盆，第i种花至多a[i]盆，求**摆花方案数**
```C++
// dp[i][j]: 前i种花，摆放了j盆的方案数
// dp[i][j] += dp[i-1][j-k] for k in [0, a[i]]
vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
dp[0][0] = 1;
for(int i=1; i<=n; i++) { // 枚举物品
    for(int j=0; j<=m; j++) { // 枚举总摆放盆数
        for(int k=0; k<=min(a[i], j); k++) { // 枚举物品i的摆放数
            dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
        }
    }
}
cout << dp[n][m] << endl;
```
### [活动安排](https://www.nowcoder.com/practice/16d971e9e42e4f3b9b1e2b8794796a43?channelPut=w25springcamp)
`贪心 - 典`
> 按结束时间排序，优先`选择结束时间最早`且`与前一个活动不冲突`的活动
```C++
int ed = -1;
for(int i=1; i<=n; i++) {
    if(a[i].first >= ed) {
        ans ++;
        ed = a[i].second;
    }
}
```
### [哇，这就是5p](https://www.luogu.com.cn/problem/P11998?contestId=236568)
`暴力：二进制枚举` && `正解：概率dp`
1. 二进制枚举: n<=15(20分)
```C++
ll ans = 0; // 总分是m的倍数的概率
// 枚举二进制
for(int i=0; i<(1 << n); i++) {
    // 十进制转二进制(01序列)
    int t; vector<int> v;
    while(t) {
        v.push_back(t % 2);
        t /= 2;
    }
    while(v.size() < n) v.push_back(0);
    ll sum = 0, P = 1; // 该序列总分和概率
    // 枚举01序列：0做错，1做对
    for(int i=0; i<n; i++) {
        if(v[i]) {
            sum += a[i + 1];
            (P *= p[i + 1]) %= mod;
        } else (P *= 1 - p[i + 1]) %= mod;
    }
    if(sum % m != 0) continue; // 不是m的倍数
    (ans += P) %= mod;
}
```
2. 概率dp(50分，二维，该题卡二维)
> 概率dp的第二维一般都与答案强相关
> 该题求：得分是m的倍数的概率 -> **得分%m==0的概率**
> dp[i][j]: 前i题，**得分%m为j的概率**, res = dp[n][0]
```C++
vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
dp[0][0] = 1;
for(int i=1; i<=n; i++) {
    for(int j=0; j<m; j++) {
        (dp[i][j] = dp[i-1][j] * (1 - p[i]) % mod + dp[i-1][(j - a[i] + mod) % mod] * p[i] % mod) %= mod;
    }
}
//* 该题dp有可能是负数（因为1-p[i]）
cout << (dp[n][0] + mod) % mod << endl;
```
3. 概率dp(100分，一维)
> 新开一个pre数组记录dp的上一维：dp在j:0~m时出现了dp[**(j-a[i]+m)%m**]所以可能会出现已经被更新的dp，但需要的是上一维的dp。
```C++
vector<ll> dp(m + 1);
dp[0] = 1;
vector<ll> pre = dp; // 记录上一维
for(int i=1; i<=n; i++) {
    for(int j=0; j<m; j++) {
        (dp[j] = pre[j] * (1 - p[i]) % mod + pre[(j - a[i] + m) % m] * p[i] % mod) %= mod;
    }
    pre = dp;
}
cout << (dp[0] + mod) % mod << endl;
```