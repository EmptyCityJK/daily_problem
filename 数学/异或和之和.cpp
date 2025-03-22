#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    // 求[l,r]的异或和: pre[r] ^ pre[l-1](自反性：a^b^b = a)
    // => 求两两异或前缀和的异或值(0 和 1搭配才有贡献值)
    vector<ll> a(n + 1);
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for(int k=0; k<=21; k++) {
        int one = 0, zero = 1; // pre[0] = 0
        for(int i=1; i<=n; i++) {
            if(a[i] >> k & 1) one ++;
            else zero ++;
        }
        ans += (1ll << k) * one * zero;
    }
    cout << ans << endl;
    return 0;
}
