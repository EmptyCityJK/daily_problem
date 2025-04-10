    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> g[n + 1];
        for(int i=1; i<n; i++) {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<int> depth(n + 1);
        vector<vector<int>> fa(n + 1, vector<int>(31));
        vector<int> dist(n + 1);
        function<void(int, int, int)> dfs = [&] (int u, int f, int d) {
            depth[u] = d;
            for(auto [v, w]: g[u]) {
                if(v == f) continue;
                fa[v][0] = u;
                dist[v] = dist[u] + w;
                for(int k=1; k<=30; k++)
                    fa[v][k] = fa[fa[v][k-1]][k-1];
                dfs(v, u, d + 1);
            }
        };
        vector<int> lg(n + 1);
        for(int i=1; i<=n; i++)
            lg[i] = lg[i-1] + (1 << lg[i-1] == i);
        auto lca = [&] (int x, int y) {
            if(depth[x] < depth[y]) swap(x, y);
            while(depth[x] > depth[y])
                x = fa[x][lg[depth[x]-depth[y]] - 1];
            if(x == y) return x;
            for(int k=lg[depth[x]]; k>=0; k--) {
                if(fa[x][k] != fa[y][k]) {
                    x = fa[x][k];
                    y = fa[y][k];
                }
            }
            return fa[x][0];
        };
        dfs(1, -1, 1);
        while(m --) {
            int x, y; cin >> x >> y;
            int p = lca(x, y);
            int ans = dist[x] + dist[y] - 2 * dist[p];
            cout << ans << endl;
        }
        return 0;
    }