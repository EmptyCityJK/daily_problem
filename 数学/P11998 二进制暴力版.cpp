#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244853;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), p(n + 1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> p[i];
    // n, m <= 15
    // 二进制枚举
    ll ans = 0;
    for(int i=0; i<(1 << n); i++) {
        int t = i;
        vector<int> v;
        while(t) {
            v.push_back(t % 2);
            t /= 2;
        }
        while(v.size() < n) v.push_back(0);

        ll sum = 0;
        ll P = 1; 
        // 枚举二进制位
        for(int i=0; i<n; i++) {
            if(v[i]) { // 为 1
                sum += a[i + 1];
                (P *= p[i + 1]) %= mod;
            } else {
                (P *= 1 - p[i + 1]) %= mod;
            }
        }
        if(sum % m != 0) continue; 
        (ans += P) %= mod;
    }
    cout << (ans + mod) % mod << endl;
}