#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
inline void solve() { 
    int n, q, s; cin >> n >> q >> s;
    vector<int> g[n+1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n+1);
    vector<vector<int>> fa(n+1, vector<int>(40));
    function<void(int, int, int)> dfs = [&](int u, int f, int d) {
        depth[u] = d;
        for(int v: g[u]) {
            if(v == f) continue;
            fa[v][0] = u;
            for(int i=1; i<=30; i++) {
                fa[v][i] = fa[fa[v][i-1]][i-1];
            }
            dfs(v, u, d+1);
        }
    };
    dfs(s, -1, 1);
    vector<int> lg(n+1);
    for(int i=1; i<=n; i++)
        lg[i] = lg[i-1] + ((1<<lg[i-1]) == i);
    auto lca = [&](int x, int y) {
        if(depth[x] < depth[y]) swap(x, y);
        // 先跳到同一高度
        while(depth[x] > depth[y]) 
            x = fa[x][lg[depth[x] - depth[y]] - 1];
        if(x == y) return x;
        // 一起往上跳
        for(int k=lg[depth[x]]; k>=0; k--) {
            if(fa[x][k] != fa[y][k]) {
                x = fa[x][k];
                y = fa[y][k];
            }
        }
        return fa[x][0];
    };
    // 询问a结点和b结点的最近公共祖先
    while(q --) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}