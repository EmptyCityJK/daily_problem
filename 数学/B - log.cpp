#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
1 + 2 + ... + k <= n + 1
(1 + k) * k <= 2 * (n + 1)
其余直接单独买
*/
int main() {
    ll n; cin >> n;
    function<ll(ll)> f = [&](ll k) {
        return (1LL + k) * k / 2;
    };
    // 找到k的最大值(右边界)
    ll l = 0LL, r = sqrt(2*(n + 1));
    while(l < r) {
        ll mid = (l + r + 1) >> 1;
        // cout << mid << endl;
        if(f(mid) <= (n + 1)) l = mid;
        else r = mid - 1;
    }
    cout << n - l + 1 << endl;
    return 0;
}