#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int primes[N], cnt;
bool st[N];
inline void get_prime(int n) {
    for(int i=2; i<=n; i++) {
        if(!st[i]) primes[cnt ++] = i;
        for(int j=0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    get_prime(1e5);
    vector<int> depth(n + 1);
    vector<int> num(n + 1); // 从1号点到其他点，需要打好关系的公司数量
    vector<vector<int>> fa(n + 1, vector<int>(31));
    function<void(int, int, int)> dfs = [&](int u, int f, int d) {
        depth[u] = d;
        for(int v: g[u]) {
            if(f == v) continue;
            fa[u][0] = v;
            for(int i=1; i<=30; i++) {
                fa[u][i] = fa[fa[u][i-1]][i-1];
            }
            num[v] = num[u];
            for(int i=0; i<cnt && a[v]<=primes[i]; i++) {
                if(a[v] % primes[i] == 0)
                    num[v] ++;
            }
            dfs(v, u, d + 1);
        }
    };
    for(int i=0; i<cnt; i++) {
        if(a[1] % primes[i] == 0) {
            num[1] ++;
        }
    }
    dfs(1, -1, 1);
    // for(int i=1; i<=n; i++)
    //     cout << num[i] << " ";
    vector<int> lg(n + 1);
    for(int i=1; i<=n; i++)
        lg[i] = lg[i-1] + (1<<lg[i-1] == i);
    auto lca = [&](int x, int y) {
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
    while(q --) {
        int st, ed; cin >> st >> ed;
        int p = lca(st, ed);
        int ans = max(num[st]-num[fa[p][0]], num[ed]-num[fa[p][0]]);
        cout << ans << endl;
    }
    return 0;
}