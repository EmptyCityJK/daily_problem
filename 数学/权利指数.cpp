#include <bits/stdc++.h>
using namespace std;
int a[25], ans[25];
inline void solve() {
    int n; cin >> n;
    memset(ans, 0, sizeof ans);
    int sum = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // 二进制枚举
    for(int k=1; k<(1<<n); k++) {
        int tot = 0;
        for(int i=0; i<n; i++)
            if(k>>i & 1) tot += a[i+1];
        if(tot > sum / 2)
            for(int i=0; i<n; i++)
                if(k>>i & 1)
                    if(tot - a[i+1] <= sum / 2)
                        ans[i+1] ++;
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t --)
    solve();
    return 0;
}