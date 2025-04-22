#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i=1; i<=n; i++) cin >> a[i];
    // dp[i][j]: 前i个数，对k取模得j的最大和
    // vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1e18));
    // dp[0][0] = 0;
    // dp[j]: 对k取模得j的最大和
    vector<ll> dp(k+1, -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        auto pre = dp; // 模拟滚动数组
        for(int j=0; j<k; j++) {
            if(pre[j] != -1) // pre[j] 被更新过
            dp[(j + a[i]) % k] = max(pre[(j + a[i]) % k], pre[j] + a[i]);
        }
    }
    if(dp[0] == 0) cout << -1 << endl;
    else cout << dp[0] << endl;
    return 0;
}