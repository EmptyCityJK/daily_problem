#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;
inline void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n + 1); // dp[i]: 包含点i的所有连通块的点权总和
    vector<ll> f(n + 1, 1); // f[i]: 包含点i的连通块数量
    function<void(int, int)> dfs = [&](int u, int fa) {
        dp[u] = a[u];
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            dp[u] = (dp[u] + (dp[u] * f[v] % mod + dp[v] * f[u] % mod) % mod) % mod;
            f[u] = (f[u] + f[u] * f[v] % mod) % mod;
        }
    };
    dfs(1, -1);
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}