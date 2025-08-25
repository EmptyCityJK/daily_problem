#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

inline void solve() {
    int n; cin >> n;
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n + 1, 1); //dp[i]: 以i为根的子树的ans(mex之和的最大可能值)
    vector<ll> siz(n + 1, 1); //siz[i]: 以i为根的子树的大小
    function<void(int, int)> dfs = [&](int u, int fa) {
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
        for(int v: g[u]) {
            if(v == fa) continue;
            dp[u] = max(dp[u], dp[v] + siz[u]);
        }
    };
    dfs(1, -1);
    cout << dp[1];
}

int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}