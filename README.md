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

### [【模板】01背包](https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?channelPut=w25springcamp)
`dp-01背包`
（1）求这个背包至多能装多大价值的物品？
（2）若背包**恰好装满**，求至多能装多大价值的物品？
```cpp
int n, V; cin >> n >> V;
vector<int> dp(V + 1); // dp[i]: 背包容量为i时的最大价值
vector<int> f(V + 1); // f[i]: 恰好装体积i的物品的最大价值
for(int i=1; i<=n; i++) {
    int v, w; cin >> v >> w;
    for(int j=V; j>=v; j--) {
        dp[j] = max(dp[j], dp[j-v] + w);
        if(j == v || f[j - v])
            f[j] = max(f[j], f[j - v] + w);
    }
}
cout << dp[V] << endl << f[V];
```
###  [【模板】完全背包](https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?channelPut=w25springcamp)

`dp-完全背包`
(1)求这个背包至多能装多大价值的物品？
(2)若背包**恰好装满**，求至多能装多大价值的物品？

```cpp
// dp[j]: 背包容积为j时的最大价值
vector<int> dp(V + 1);
// f[j]: 恰好装j容积物品的最大价值
vector<int> f(V + 1);
for(int i=1; i<=n; i++) {
    int v, w; cin >> v >> w;
    for(int j=v; j<=V; j++) {
        dp[j] = max(dp[j], dp[j-v] + w);
        if(j==v || f[j-v])
            f[j] = max(f[j], f[j-v] + w);
    }
}
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
// 写法2：更省时间 防卡常
for(int k=0; k<(1<<k); k++) {
    ll sum = 0, P = 1;
    for(int i=0; i<n; i++) {
        if(k << i & 1) {
            sum += a[i + 1];
            (P *= p[i + 1]) %= mod;
        } else (P *= 1 - p[i + 1]) %= mod;
    }
    if(sum % m != 0) continue;
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
### [【模板】哈夫曼编码](https://www.nowcoder.com/practice/4c0419eb07c840ca8402e4f2a52cfd49?channelPut=w25springcamp)
> [前缀知识 哈夫曼树和哈夫曼编码](https://zhuanlan.zhihu.com/p/687698948)

`dfs/结论`
1. 结论
每个叶子节点的权重（频次）会在哈夫曼树中出现`depth[deaf]`次，故统计字符串在哈夫曼编码后的最短长度：
`ans += cnt[i] * depth[i](i = 1, 2, ..., n) -> ans += cnt[u] + cnt[v]`
2. 优先队列+dfs
```C++
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> g[2 * n + 1];
    while(q.size()) {
        if(q.size() == 1) {
            break;
        } // 频率，编号
        auto [u, ui] = q.top(); q.pop();
        auto [v, vi] = q.top(); q.pop();
        ll sum = u + v;
        q.push({sum, ++ id});
        g[id].push_back(ui);
        g[id].push_back(vi);
    }
    vector<ll> dep(id+1);
    function<void(int)> dfs = [&](int u) {
        for(int v: g[u]) {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
        return ;
    };
    dfs(id);
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans += cnt[i] * dep[i];
```
### [相差不超过k的最多数](https://www.nowcoder.com/practice/562630ca90ac40ce89443c91060574c6?channelPut=w25springcamp)
`典 - 二分`

枚举左端点l，求满足(abs(a[r]-a[l])<=k)的右端点最大值(l=mid)

> [二分库函数 lower_bound/upper_bound](https://github.com/EmptyCityJK/daily_problem/blob/main/C%2B%2B%E7%AE%97%E7%AB%9E%E5%B8%B8%E7%94%A8%E5%BA%93%E5%87%BD%E6%95%B0.md)
```C++
for(int i=1; i<=n; i++) {
    int l = i, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid, i)) l = mid;
        else r = mid - 1;
    }
    ans = max(ans, l - i + 1);
}
```
**使用库函数：**
> `upper_bound(a.begin()+1, a.end(), a[i]+k): `
> 找到第一个>a[i]+k的元素的迭代器
> `prev(...): `
> 获取前一个迭代器
> 相当于找到最后一个元素<=a[i]+k的元素
> `prev(upper_bound(...)) - a.begin(): `
> 获取该元素的索引下标
```C++
for(int i=1; i<=n; i++) {
    int r = prev(upper_bound(a.begin()+1, a.end(), a[i]+k)) - a.begin();
    res = max(res, r - i + 1);
}
```
### [【模板】最近公共祖先](https://www.luogu.com.cn/problem/P3379)
`LCA`
> 1. dfs/bfs求depth和fa
> 2. lca(int x, int y)：
> 3. 确保depth[x] > depth[y]
> 4. 将x跳到与y同一深度
> 5. 如果x == y，返回x
> 6. 否则将x和y同时往上跳直到第一次fa[x][k] == fa[y][k]，返回fa[x][0]
```cpp
vector<int> depth(n + 1);
vector<vector<int>> fa(n + 1, vector<int>(31));
function<void(int, int, int)> dfs = [&](int u, int f, int d) {
    depth[u] = d;
    for(int v: g[u]) {
        if(v == f) continue;
        fa[v][0] = u;
        for(int i=1; i<=30; i++) 
            fa[v][i] = fa[fa[v][i-1]][i-1];
        dfs(v, u, d+1);
    }
};
vector<int> lg(n + 1);
for(int i=1; i<=n; i++)
    lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
auto lca = [&](int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    while(depth[x] > depth[y])
        x = fa[x][lg[depth[x]-depth[y]] - 1];
    if(x == y) return x;
    for(int k=30; k>=0; k--) {
        if(fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];
};
dfs(1, -1, 1);
// 查询
int a, b; cin >> a >> b;
cout << lca(a, b) << endl;
```
### [没有上司的舞会](https://www.luogu.com.cn/problem/P1352)

`树形dp`
> 题意：每个节点都有一个快乐指数。当父节点被选择时，子节点无法被选择，求最大快乐指数。
> 
> Tips. 每个结点都有选或不选两种状态，所以需要开一个二维数组``dp[i][j]``。对于选择当前顶点(`dp[v][1]`)，那么其子节点一定不选(`dp[u][0]`)；对于不选择当前顶点(`dp[v][0]`)，那么其子节点存在两种情况：选其子节点(`dp[u][1]`)或者不选其子节点(`dp[u][0]`)。选其子节点的情况很好理解，不选其子节点的情况存在的原因是：孩子并不是必选的，因为它可能“阻挡”了更深层的更大收益
例子：假设这里有一个小树

```yaml
   v
   |
   u
  / \
 w   x
```

快乐值：

- `r[v] = 1`
- `r[u] = 10`
- `r[w] = 10`
- `r[x] = 10`

如果 **不选 v**：

- **选 u**：得到 `10 + dp[w][0] + dp[x][0] = 10 + 0 + 0 = 10`
- **不选 u**：得到 `max(dp[w][0],dp[w][1]) + max(dp[x][0],dp[x][1]) = 10 + 10 = 20`

结果是：虽然 `r[u]` 是正数，但「不选 u」反而能获得更大的总和！

```cpp
// dp[i][0]: 不选择i号点时，以i为根的子树的最大快乐指数
// dp[i][1]: 选择i号点时，以i为根的子树的最大快乐指数
vector<vector<int>> dp(n + 1, vector<int>(2));
for(int i=1; i<=n; i++)
    dp[i][1] = r[i];
function<void(int, int)> dfs = [&](int v, int f) {
    for(int u : g[v]) {
        if(u == f) continue;
        dfs(u, v);
        dp[v][1] += dp[u][0];
        dp[v][0] += max(dp[u][0], dp[u][1]);
    }
};
```

### [旅游]([旅游](https://ac.nowcoder.com/acm/problem/15748))

与上一题(没有上司的舞会)基本一致，相当于快乐指数都为1的特殊情况。

### [小美的树上染色]([小美的树上染色](https://ac.nowcoder.com/acm/problem/257808))

`贪心 + 树形dp`

> 题意：一棵树，每个节点有一个权值。初始每个节点都是白色。有若干次操作，每次操作可以选择两个相邻的节点，如果它们都是白色且权值的乘积是完全平方数，可以把这两个节点同时染红。问最多可以染红多少节点？
>
> Tips. 贪心思想，局部最优：**从叶子节点往上**，遇到符合要求的就染。判断：该局部最优能达到全局最优。

```cpp
// 判断一个数是不是完全平方数
auto check = [&](ll x) {
    ll sq = sqrt(x);
    return sq*sq == x;
};
int ans = 0;
vector<bool> st(n + 1);
// 从叶子结点向上 遇到符合要求的就染
function<void(int, int)> dfs = [&](int v, int f) {
    for(int u: g[v]) {
        if(u == f) continue;
        dfs(u, v);
        if(st[u] || st[v]) continue;
        ll res = w[u] * w[v];
        if(check(res)) {
            ans += 2;
            st[u] = 1, st[v] = 1;
        }
    }
};
```

### [E-小红的树形 dp_牛客周赛 Round 34](https://ac.nowcoder.com/acm/contest/75766/E)

`树形dp`

> 题意：一棵树，每个节点对应一个由‘?’, ‘d’, ‘p’组成的字符串的相应字符，‘?’可以变成‘d’或‘p’，符合要求的字符串需要满足将所有'?'字符变成'd'或者'p'字符后，任意两个相邻节点的字符不同。不存在该情况输出“-1”，存在则输出符合要求的字符串。
>
> 思路：
> **从上往下**深度遍历，**保证当前节点的父节点已确认字符**，如果其与父节点不符合要求flag修改为false，如果其为‘?’则根据其父节点的字符直接修改。
> 在进行完上述操作后，遍历当前节点的子节点，如果当前节点及其子节点不符要求则修改flag为false，判断完后进行：`flg &= dfs(u, v)`，保证flg记录的是`以v结点为根的子树是否符合要求`（flg有0则全为0）
> 另外还需注意：当起点（结点0）为 ‘?’ 时无法根据父节点修改，所以需进行分支判断：先尝试修改为‘d’再尝试修改为‘p’。

```cpp
// 以v结点为根的子树是否符合要求
function<bool(int, int)> dfs = [&] (int v, int f) {
    bool flg = 1;
    // 不为起点 且 当前顶点与父亲结点字母相同
    if(v != 0 && s[v] == s[f]) flg = 0;
    // 不为起点 且 当前顶点为?
    if(v != 0 && s[v] == '?') {
        if(s[f] == 'd') s[v] = 'p';
        else s[v] = 'd';
    }
    // 此时，当前顶点v的字母已确定
    for(int u: g[v]) {
        if(u == f) continue;
        if(s[v] == s[u]) flg = 0;
        flg &= dfs(u, v);
    }   
    return flg;
};
if(s[0] == '?') {
    string t = s;
    s[0] = 'd';
    if(!dfs(0, -1)) {
        s = t;
        s[0] = 'p';
        if(!dfs(0, -1)) cout << -1 << endl;
        else cout << s << endl;
    } else cout << s << endl;
} else {
    if(!dfs(0, -1)) cout << -1 << endl;
    else cout << s << endl;
}
```

