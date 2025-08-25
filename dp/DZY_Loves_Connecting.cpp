#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
inline void solve()
{
    int n; cin >> n;
    vector<int> g[n + 1];
    for(int i=2; i<=n; i++) {
        int p; cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    vector<ll> dp(n + 1, 1); // dp[i]: 包含i在内的所有连通块的大小之和
    vector<ll> f(n + 1, 1); // f[i]: 包含i在内的连通块数量
    function<void(int, int)> dfs = [&](int u, int fa) {
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            dp[u] = (dp[u] + (dp[u] * f[v] % mod + dp[v] * f[u] % mod) % mod) % mod;
            f[u] = (f[u] + f[u] * f[v] % mod) % mod;
        }
    };
    dfs(1, -1);
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans = (ans + dp[i]) % mod;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // cout << fixed << setprecision(10);
    int t; cin >> t;
    while(t --)
    solve();
    return 0;
}