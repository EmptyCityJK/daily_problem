#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> g[n + 1];
    for(int i=1; i<=n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(a == b) {
        cout << "NO" << endl;
        return ;
    }
    bool in = 0; // b在环上
    int id = 0; // 交汇点
    vector<bool> vis(n + 1, false);
    vector<int> dis(n + 1); int disb = 0;
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        if(in || id) return ;
        for(int v: g[u]) {
            if(v == fa) continue;
            if(v == b) {
                in = 1;
                return ;
            }
            if(vis[v]) {
                id = v;
                return ;
            }
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            dfs1(v, u);
        } 
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for(int v: g[u]) {
            if(v == fa) continue;
            if(v == id) {
                return ;
            }
            dis[v] = dis[u] + 1;
            dfs2(v, u);
        }
    };
    vis[b] = 1;
    dfs1(b, -1);
    disb = dis[id];
    if(in) {
        cout << "YES" << endl;
        return ;
    }
    vis.assign(n + 1, false);
    dis.assign(n + 1, 0);
    dfs2(a, -1);
    int disa = dis[id];
    if(disa > disb) {
        cout << "YES" << endl;
        return ;
    }
    cout << "NO" << endl;
}
int main() {
    int t; cin >> t;
    while(t --)
    solve();
    return 0;
}