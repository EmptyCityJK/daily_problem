#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<ll> a(n + 1, 0), pre(n + 1, 0);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    ll tot = pre[n];
    if(tot % 3) {
        cout << 0 << endl;
        return 0;
    }
    ll t = tot / 3;
    int loc = 0;
    ll ans = 0;
    vector<ll> lst(n + 1); // 最后一个正数出现的位置
    vector<ll> cnt(n + 1); // 1~i的t出现次数
    for(int i=1; i<=n; i++) {
        cnt[i] = cnt[i-1];
        if(a[i] > 0) {
            loc = i;
        }
        // cout << loc << endl;
        lst[i] = loc;
        if(pre[i] == t) {
            cnt[i] = cnt[i-1] + 1;
            // cout << cnt[i] << endl;
        }
        else if(pre[i] == 2*t) {
            ans += cnt[lst[i]];
        }
    }
    cout << ans << endl;
    return 0;
}