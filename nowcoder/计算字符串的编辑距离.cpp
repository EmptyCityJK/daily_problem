#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    //dp[i][j]: a[0 ~ i-1]与b[0 ~ j-1]之间的编辑距离
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            // 插入，删除a，删除b
            else {
                dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
}