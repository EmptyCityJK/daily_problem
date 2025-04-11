#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, V; cin >> n >> V;
    // dp[i][j]: 前i种物品，背包容积为j时的最大价值
    vector<int> dp(V + 1);
    // f[i][j]: 前i种物品，恰好装j容积物品的最大价值
    vector<int> f(V + 1);
    for(int i=1; i<=n; i++) {
        int v, w; cin >> v >> w;
        for(int j=v; j<=V; j++) {
            dp[j] = max(dp[j], dp[j-v] + w);
            if(j==v || f[j-v])
                f[j] = max(f[j], f[j-v] + w);
        }
    }
    cout << dp[V] << endl << f[V];
    return 0;
}