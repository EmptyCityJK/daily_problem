#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;

inline void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    ll res = 0;
    for(int k=0; k<=60; k++) {
        ll zero = 0, one = 0;
        ll tot = 0;
        ll powk = (1ll << k) % mod; 
        for(int i=1; i<=n; i++) {
            if(a[i] >> k & 1) {
                tot += zero;
                one ++;
            } else {
                tot += one;
                zero ++;
            }
            tot %= mod;
        }
        (res += tot * powk % mod) %= mod;

    }
    cout << res << endl;
}

int main()
{
    int t=1;
    while(t --)
        solve();
    return 0;
}