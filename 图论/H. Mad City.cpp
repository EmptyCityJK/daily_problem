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
    int id = 0, minn = 1e9; // b到环的最小距离交汇点
    vector<int> dis(n + 1, -1); // b到其他点的距离
    function<void(int, int, int)> dfs1 = [&](int u, int fa, int tot) {
        if(dis[u] == -1) dis[u] = tot;
        else { // 已经来过
            if(dis[u] < minn) { // 能更新
                minn = dis[u];
                id = u;
            }
            return ;
        }
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs1(v, u, tot + 1);
        }
    };
    dfs1(b, 0, 0);
    int disb = dis[id];
    dis.assign(n + 1, -1); // a到其他点的距离
    function<void(int, int, int)> dfs2 = [&](int u, int fa, int tot) {  
        if(dis[u] == -1) dis[u] = tot;
        else {  // 来过
            if(dis[u] > tot) dis[u] = tot; // 能更新，继续搜
            else return ; // 不能更新->该路径没潜力，回溯
        }
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs2(v, u, tot + 1);
        }
    };
    dfs2(a, 0, 0);
    int disa = dis[id];
    if(disa > disb)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
    int t; cin >> t;
    while(t --)
    solve();
    return 0;
}