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
    vector<ll> w(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 判断一个数是不是完全平方数
    auto check = [&](ll x) {
        ll sq = sqrt(x);
        return sq*sq == x;
    };
    int ans = 0;
    vector<bool> st(n + 1);
    // 从叶子结点向上 遇到符合要求的就染
    function<void(int, int)> dfs = [&](int v, int f) {
        for(int u: g[v]) {
            if(u == f) continue;
            dfs(u, v);
            if(st[u] || st[v]) continue;
            ll res = w[u] * w[v];
            if(check(res)) {
                ans += 2;
                st[u] = 1, st[v] = 1;
            }
        }
    };
    dfs(1, -1);
    cout << ans << endl;
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