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
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }
    // dp[i][j]: 前i题，得分 %m 为 j 的概率
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = dp[i-1][j] * (1 - p[i]) % mod + dp[i-1][(j - a[i] + m) % m] * p[i] % mod;
            dp[i][j] %= mod;
        }
    }
    cout << (dp[n][0] + mod) % mod << endl;
    return 0;
}