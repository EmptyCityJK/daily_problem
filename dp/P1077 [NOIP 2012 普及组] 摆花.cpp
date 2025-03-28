#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6 + 7;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    // dp[i][j]: 前i种花，摆放了j盆的方案数
    // dp[i][j] += dp[i-1][j-k] for k in [0, min(a[i], j)]
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            for(int k=0; k<=min(a[i], j); k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}