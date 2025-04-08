#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> pre(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> pre[i]; pre[i] += pre[i-1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int i=n; i>=1; i--) {
        for(int j=i; j<=n; j++) {
            dp[i][j] = pre[j] - pre[i-1];
            // cout << dp[i][j] << " ";
            if(i <= j-1) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i+1 <= j) dp[i][j] = max(dp[i][j], dp[i+1][j]);
            // cout << dp[i][j] << " " << endl;
        }
    }
    // cout << endl;
    cout << dp[1][n] << endl;
}