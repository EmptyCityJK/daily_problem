#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a.begin()+1, a.begin()+1+n);
    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1] + a[i];
    }
    int ans = 0;
    for(int i=n; i>=1; i--) {
        int mx = a[i];
        if(pre[i-1] > mx) {
            ans = pre[i-1] + mx;
            cout << ans << endl;
            return ;
        }
    }
    cout << 0 << endl;
}
int main() {
    int t; cin >> t;
    while(t --) {
        solve();
    }
    return 0;
} 