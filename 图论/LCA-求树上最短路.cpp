#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
inline void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> g[n+1];
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> depth(n+1), dis(n+1);
    vector<vector<int>> fa(n+5, vector<int>(40));
    function<void(int, int, int)> dfs = [&](int u, int f, int d) {
        depth[u] = d;
        for(auto [v, w]: g[u]) {
            if(v == f) continue;
            fa[v][0] = u;
            dis[v] = dis[u] + w;
            for(int k=1; k<=30; k++) {
                fa[v][k] = fa[fa[v][k-1]][k-1];
            }
            dfs(v, u, d+1);
        }
    };
    vector<int> lg(n+5);
    for(int i=1; i<=n; i++)
        lg[i] = lg[i-1] + (1<<lg[i-1] == i);
    auto lca = [&](int a, int b) {
        if(depth[a] < depth[b]) swap(a, b);
        // 先跳到同一高度
        while(depth[a] > depth[b])
            a = fa[a][lg[depth[a]-depth[b]]-1];
        if(a == b)
            return a;
        // 一起向上跳
        for(int i=lg[depth[a]]; i>=0; i--) {
            if(fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    };
    dfs(1, -1, 1);
    for(int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        int res = 0;
        res = dis[x] + dis[y] - dis[p]*2;
        cout << res << endl;
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}