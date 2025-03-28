#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        // 反向建图
        g[v].push_back(u);
    }
    int ans[n + 1];
    vector<bool> vis(n + 1);
    for(int i=1; i<=n; i++) ans[i] = i;
    for(int i=n; i>=1; i--) {
        queue<int> q;
        q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop(); vis[u] = 1;
            for(int t: g[u]) {
                if(vis[t]) continue;
                vis[t] = 1; q.push(t);
                ans[t] = max(i, ans[t]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
} 