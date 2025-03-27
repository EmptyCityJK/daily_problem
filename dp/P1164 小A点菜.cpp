#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    // dp[i] 花费i元的组合的方案数
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=1; j--) {
            if(j >= a[i])
                dp[j] += dp[j - a[i]];
        }
    }
    // for(int i=1; i<=m; i++) cout << dp[i] << " ";
    cout << dp[m] << endl;
    return 0;
}