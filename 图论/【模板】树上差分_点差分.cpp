// P3128 [USACO15DEC] Max Flow P
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(31));
    function<void(int, int, int)> dfs = [&](int u, int f, int d) {
        depth[u] = d;
        for(int v: g[u]) {
            if(v == f) continue;
            fa[u][0] = v;
            for(int k=1; k<=30; k++)
                fa[u][k] = fa[fa[u][k-1]][k-1];
            dfs(v, u, d + 1);
        }
    };
    vector<int> lg(n + 1);
    for(int i=1; i<=n; i++)
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    auto lca = [&](int x, int y) {
        if(depth[x] < depth[y]) swap(x, y);
        while(depth[x] > depth[y])
            x = fa[x][lg[depth[x] - depth[y]] - 1];
        if(x == y) return x;
        for(int k=lg[x]; k>=0; k--) {
            if(fa[x][k] != fa[y][k]) {
                x = fa[x][k];
                y = fa[y][k];
            }
        }
        return fa[x][0];
    };
    dfs(1, -1, 1);    
    vector<int> num(n + 1); // 差分数组
    while(k -- ) {
        int s, t; cin >> s >> t;
        int p = lca(s, t);
        int pp = fa[p][0];
        num[s] ++; num[t] ++;
        num[p] --; num[pp] --;
    }
    int ans = 0;
    function<void(int, int)> ddfs = [&](int u, int f) {
        for(int v: g[u]) {
            if(f == v) continue;
            num[u] += num[v];
            ddfs(v, u);
        }
        cout << ans << " " << num[u] << endl;
        ans = max(ans, num[u]);
    };
    ddfs(1, -1);
    for(int i=0; i<=n; i++)
        cout << num[i] << " ";
    cout << endl;
    cout << ans << endl;
    return 0;
}