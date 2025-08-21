#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 998244353;
inline void solve()
{
    int n; cin >> n;
    vector<int> r(n + 1);
    for(int i=1; i<=n; i++)
        cin >> r[i];
    vector<int> g[n + 1];
    vector<bool> st(n + 1);
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        st[u] = 1;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int s = 0; // 校长
    for(int i=1; i<=n; i++) {
        if(st[i]) continue;
        s = i;
        break;
    }
    // dp[i][0]: 不选择i号点时，以i为根的子树的最大快乐指数
    // dp[i][1]: 选择i号点时，以i为根的子树的最大快乐指数
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for(int i=1; i<=n; i++)
        dp[i][1] = r[i];
    function<void(int, int)> dfs = [&](int v, int f) {
        for(int u : g[v]) {
            if(u == f) continue;
            dfs(u, v);
            dp[v][1] += dp[u][0];
            dp[v][0] += max(dp[u][0], dp[u][1]);
        }
    };
    dfs(s, -1);
    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << max(dp[s][1], dp[s][0]) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // cout << fixed << setprecision(10);
    int t = 1;
    while(t --)
    solve();
    return 0;
}