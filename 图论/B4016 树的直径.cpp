#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1);
    int id = 0, maxn = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        for(int v: g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(1, -1);
    for(int i=1; i<=n; i++) {
        if(maxn < dep[i]) {
            maxn = max(maxn, dep[i]);
            id = i;
        }
    }
    dep.assign(n + 1, 0);
    dfs(id, -1);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans = max(ans, dep[i]);
    }
    cout << ans << endl;
    return 0;
}