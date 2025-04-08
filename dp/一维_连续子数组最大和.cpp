#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    for(int i=1; i<=n; i++) {
        if(dp[i-1] >= 0)
            dp[i] = dp[i-1] + a[i];
        else dp[i] = a[i];
    }
    int ans = -1e9;
    for(int i=1; i<=n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}