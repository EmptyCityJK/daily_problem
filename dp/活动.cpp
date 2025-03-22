#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;

struct Combi {
    vector<ll> fac, inv; // 阶乘，逆元
    ll mod;
    int n;
    Combi(int n, ll mod) : n(n), mod(mod) {
        fac.resize(n+1);
        inv.resize(n+1);
        fac[0] = 1;
        for(int i=1; i<=n; i++) 
            fac[i] = fac[i-1] * i % mod;
        inv[n] = qmi(fac[n], mod-2); // 逆元公式
        for(int i=n-1; i>=0; i--) 
            inv[i] = inv[i+1] * (i+1) % mod;
    }
    ll qmi(ll a, ll b) {
        ll res = 1;
        while(b) {
            if(b & 1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    ll C(ll x, ll y) {
        if(x < y) return 0ll;
        return (fac[x] * inv[y] % mod * inv[x-y] % mod);
    }
    ll lucas(ll a, ll b) {
        if (a<mod && b<mod) return C(a, b);
        return C(a%mod, b%mod) * lucas(a / mod, b / mod) % mod;
    }
};
int main()
{
    Combi comb(1e6, mod);
    vector<ll> dp(1e6 + 1, 0); // i个人的方案数
    dp[1] = 0, dp[2] = 1, dp[3] = 1, dp[4] = 4;
    for(int i=5; i<=1e6; i++) {
        dp[i] = comb.C(i - 1, 1) * dp[i - 2] % mod;
        dp[i] += comb.C(i - 1, 2) * dp[i - 3] % mod;
        dp[i] %= mod;
        dp[i] += comb.C(i - 1, 3) * dp[i - 4] % mod;
        dp[i] %= mod;
    }
    int t; cin >> t;
    while(t -- ) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}