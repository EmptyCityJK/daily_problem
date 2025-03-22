#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n + 1); // dp[i]: 以i为根节点的子树的陡峭值
    vector<int> fa(n + 1); // fa[i]: i的父节点
    function<void(int, int)> dfs = [&](int u, int f) {
        fa[u] = f;
        for(auto v: g[u]) {
            if(v == f) continue;
            dfs(v, u);
            dp[u] += dp[v] + abs(u - v);
        }
    };
    dfs(1, 0);
    ll ans = 2e18;
    // 断i和fa[i]的边后的(1为根节点)陡峭值
    for(int i=2; i<=n; i++)
        ans = min(ans, abs(dp[1] - abs(i - fa[i]) - 2*dp[i]));
    cout << ans << endl;
    return 0;
}