#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cout << fixed << setprecision(10);
    int n, t;
    double p;
    cin >> n >> p >> t;
    // dp[i][j]: 第j秒时 扶梯有i个人的概率
    // dp[i][j] = dp[i-1][j-1] * p + dp[i][j-1] * (1-p)
    vector<vector<double>> dp(n + 1, vector<double>(t + 1));
    dp[0][0] = 1;
    for(int j=1; j<=t; j++) {
        dp[0][j] = dp[0][j-1] * (1-p);
        for(int i=1; i<=min(n, j); i++) {
            if(i == n) dp[i][j] = dp[i-1][j-1] * p + dp[i][j-1];
            else dp[i][j] = dp[i-1][j-1] * p + dp[i][j-1] * (1-p);
        }
    }
    double ans = 0.0;
    for(int i=1; i<=n; i++) {
        ans += dp[i][t] * i;
    }
    cout << ans << endl;
    return 0;
}