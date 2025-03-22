#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline void solve() {
    int n; cin >> n;
    map<int, int> mp;
    int ans = 1e9;
    for(int i=1; i<=n; i++) {
        int t; cin >> t;
        if(mp[t] == 0) {
            mp[t] = i;
        } else ans = min(ans, i - mp[t] + 1);
    }
    if(ans != 1e9)
        cout << ans << endl;
    else cout << -1 << endl;
}

int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}