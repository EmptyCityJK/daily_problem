#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, vector<int>> mp;
    for(int i=0; i<n; i++) {
        mp[s[i]].push_back(i);
    }
    bool flg = 1;
    for(auto t: mp) {
        if(t.second.size() > 1) {
            flg = 0;
            break;
        }
    }
    if(flg) {
        cout << -1 << endl;
        return ;
    }
    int ans = 1e9;
    for(auto [c, a] : mp) {
        int m = a.size();
        if(m <= 1) continue;
        ans = min(ans, a[0] + n - a[m - 1] - 1);
        // cout << ans << " " << a[m - 1] << " " << a[0] << " " << c << endl;
        for(int i=0; i<m-1; i++) {
            ans = min(ans, a[i+1] - a[i] - 1);
        }
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t --)
    solve();
}