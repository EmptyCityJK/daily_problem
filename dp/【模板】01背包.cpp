#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, V; cin >> n >> V;
    vector<int> dp(V + 1); // dp[i]: 背包容量为i时的最大价值
    vector<int> f(V + 1); // f[i]: 恰好装体积i的物品的最大价值
    for(int i=1; i<=n; i++) {
        int v, w; cin >> v >> w;
        for(int j=V; j>=v; j--) {
            dp[j] = max(dp[j], dp[j-v] + w);
            if(j == v || f[j - v])
                f[j] = max(f[j], f[j - v] + w);
        }
    }
    cout << dp[V] << endl << f[V];
    return 0;
} 