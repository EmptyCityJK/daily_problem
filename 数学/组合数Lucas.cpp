#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;

struct Combi {
    vector<ll> fac, inv;
    ll mod;
    int n;
    Combi(int n, ll mod) : n(n), mod(mod) {
        fac.resize(n+1);
        inv.resize(n+1);
        fac[0] = 1;
        for(int i=1; i<=n; i++) 
            fac[i] = fac[i-1] * i % mod;
        inv[n] = qmi(fac[n], mod-2);
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

