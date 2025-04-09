#include <bits/stdc++.h>
using namespace std;
const int N = 40005;
int main() {
    int n; cin >> n;
    vector<int> g[N + 1];
    int root = 0;
    for(int i=1; i<=n; i++) {
        int u, v; cin >> u >> v;
        if(v == -1) {
            root = u;
            continue;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(N + 1, -1); // 深度
    // fa[i][j]: 从i号节点跳2^j步到的节点
    vector<vector<int>> fa(N + 1, vector<int>(16, 0));
    auto bfs = [&](int root) {
        queue<int> q;
        q.push(root); 
        depth[0] = 0, depth[root] = 1;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int v: g[u]) {
                if(depth[v] != -1) continue;
                depth[v] = depth[u] + 1;
                fa[v][0] = u;
                q.push(v);
                for(int k=1; k<=15; k++) {
                    fa[v][k] = fa[fa[v][k-1]][k-1];
                }
            }
        }
    };
    bfs(root);
    auto lca = [&](int x, int y) {
        if(depth[x] < depth[y]) swap(x, y);
        for(int k=15; k>=0; k--) {
            if(depth[fa[x][k]] >= depth[y]) {
                x = fa[x][k];
            } 
        }
        if(x == y) return y;
        for(int k=15; k>=0; k--) {
            if(fa[x][k] != fa[y][k]) {
                x = fa[x][k];
                y = fa[y][k];
            } 
        }
        return fa[x][0];
    };
    int m; cin >> m;
    while(m --) {
        int x, y; cin >> x >> y;
        int z = lca(x, y);
        if(z == x) puts("1");
        else if(z == y) puts("2");
        else puts("0");
    }
    return 0;
}