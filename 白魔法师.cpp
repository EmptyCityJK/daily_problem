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
    string s; cin >> s;
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        u --; v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    int ans = 0; 
    int id = 1; // 连通块编号
    int num = 0; // 连通块大小
    vector<int> ids(n + 1, 0); // 第i个点的所属连通块
    map<int, int> size; // i号连通块大小
    function<void(int, int)> dfs = [&](int v, int f) {
        ids[v] = id;
        num ++;
        for(int u: g[v]) {
            if(u == f || s[u] == 'B' || ids[u] != 0) continue;
            dfs(u, v);
        }
    };
    // 维护最大白色连通块
    for(int i=0; i<n; i++) {
        num = 0;
        // 只走没走过的白色
        if(s[i] == 'W' && ids[i] == 0) {
            dfs(i, -1);
            size[id ++] = num;
            ans = max(ans, num);
        }
    }
    // 是否存在黑色点能连接多个白色连通块
    for(int i=0; i<n; i++) {
        if(s[i] == 'B') {
            int tot = 0;
            for(int v: g[i])
                if(ids[v])
                    tot += size[ids[v]];
            ans = max(ans, tot + 1);
        }
    }
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