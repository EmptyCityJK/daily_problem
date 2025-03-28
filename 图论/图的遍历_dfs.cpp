#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        g[v].push_back(u); // 反向建边
    }
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
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
} 