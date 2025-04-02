#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244853;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), p(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for(int i=1; i<=n; i++) cin >> p[i];
    vector<ll> dp(m + 1);
    dp[0] = 1;
    vector<ll> pre = dp; // 记录上一维
    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            (dp[j] = pre[j] * (1 - p[i]) % mod + pre[(j - a[i] + m) % m] * p[i] % mod) %= mod;
        }
        pre = dp;
    }
    cout << (dp[0] + mod) % mod << endl;
    return 0;
}