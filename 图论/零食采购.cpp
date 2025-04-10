#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> c(n + 1);
    for(int i=1; i<=n; i++)
        cin >> c[i];
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(31));
    function<void(int, int, int)> dfs = [&] (int u, int f, int d) {
        depth[u] = d;
        for(int v: g[u]) {
            if(v == f) continue;
            fa[v][0] = u;
            for(int i=1; i<=30; i++)
                fa[v][i] = fa[fa[v][i-1]][i-1];
            dfs(v, u, d+1);
        }
    };
    vector<int> lg(n + 1);
    for(int i=1; i<=n; i++)
        lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
    auto lca = [&] (int x, int y) {
        if(depth[x] < depth[y]) swap(x, y);
        while(depth[x] > depth[y])
            x = fa[x][lg[depth[x] - depth[y]] - 1];
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
    while(q --) {
        int s, t;
        cin >> s >> t;
        int p = lca(s, t);
        set<int> st; 
        st.insert(c[s]), st.insert(c[t]), st.insert(c[p]);
        while(s != p) {
            s = fa[s][0];
            st.insert(c[s]);
        }
        while(t != p) {
            t = fa[t][0];
            st.insert(c[t]);
        }
        cout << st.size() << endl;
    }
    return 0;
}