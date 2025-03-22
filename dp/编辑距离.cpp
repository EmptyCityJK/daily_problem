#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    for(int i=1; i<=n; i++) {
        string s; cin >> s;
        a[i] = s;
    }
    vector<string> b(m + 1);
    vector<int> tot(m + 1);
    for(int i=1; i<=m; i++) {
        int num; string s; cin >> s >> num;
        b[i] = s;
        tot[i] = num;
        // cout << b[i-1] << " " << tot[i-1] << endl;
    }
    for(int k=1; k<=m; k++) { // 询问
        int ans = 0;
        for(int l=1; l<=n; l++) {
            string x = a[l], y = b[k];
            int as = x.size(), bs = y.size();
            int dp[as + 1][bs + 1];
            for(int i=0; i<=as; i++) dp[i][0] = i;
            for(int j=0; j<=bs; j++) dp[0][j] = j;
            for(int i=1; i<=as; i++) {
                for(int j=1; j<=bs; j++) {
                    if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1];
                    else {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                    }
                }
            }
            if(dp[as][bs] <= tot[k]) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}