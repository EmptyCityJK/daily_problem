#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a.begin()+1, a.begin()+1+n);
    // 枚举最大边a[i], 从a[1~i-1]找到满足一个和大于a[i]的组合的最小值
    vector<bool> dp(10001, false); // dp[i]: 和为i的组合存在与否
    dp[0] = true;
    int ans = 1e9;
    for(int i=1; i<=n; i++) { // 最大边
        for(int j=a[i]+1; j<=10000; j++) { // 和
            // dp[j]: 使用上一层的结果
            if(dp[j]) {
                ans = min(ans, j + a[i]);
                break;
            }
        }
        for(int j=10000; j>=a[i]; j--) {
            dp[j] = dp[j] | dp[j-a[i]];
        }
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t --) {
        solve();
    }
    return 0;
} 