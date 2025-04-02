#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a; cin >> a;
    string s; cin >> s; 
    int n = s.size();
    s = " " + s;
    vector<ll> pre(n + 1);
    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1] + s[i] - '0';
    }
    // pre[x1, y1] * pre[x2, y2] == a
    // pre[x1, y1] == i, pre[x2, y2] == a / i 
    map<ll, ll> mp;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            mp[pre[j] - pre[i-1]] ++;
        }
    }
    ll ans = 0;
    ll tot = 0;
    for(auto [sum, cnt]: mp) {
        tot += cnt;
        if(sum == 0) continue;
        if(a % sum == 0 && mp.count(a/sum)) {
            ans += cnt * mp[a/sum];
        }
    }
    // 0 * n = 0(a)
    if(a == 0) {
        ans += mp[0] * tot;
    }
    cout << ans << endl;
    return 0;
}