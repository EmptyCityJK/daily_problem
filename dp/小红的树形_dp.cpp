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
        u --; v --; // 与上面字符串统一
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    // 以v结点为根的子树是否符合要求
    function<bool(int, int)> dfs = [&] (int v, int f) {
        bool flg = 1;
        // 不为起点 且 当前顶点与父亲结点字母相同
        if(v != 0 && s[v] == s[f]) flg = 0;
        // 不为起点 且 当前顶点为?
        if(v != 0 && s[v] == '?') {
            if(s[f] == 'd') s[v] = 'p';
            else s[v] = 'd';
        }
        // 此时，当前顶点v的字母已确定
        for(int u: g[v]) {
            if(u == f) continue;
            if(s[v] == s[u]) flg = 0;
            flg &= dfs(u, v);
        }   
        return flg;
    };
    if(s[0] == '?') {
        string t = s;
        s[0] = 'd';
        if(!dfs(0, -1)) {
            s = t;
            s[0] = 'p';
            if(!dfs(0, -1)) cout << -1 << endl;
            else cout << s << endl;
        } else cout << s << endl;
    } else {
        if(!dfs(0, -1)) cout << -1 << endl;
        else cout << s << endl;
    }
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