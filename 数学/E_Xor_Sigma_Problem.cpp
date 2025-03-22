#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> cnt(64, vector<int>(n+1));
    for(int k=0; k<=30; k++) {
        for(int i=1; i<=n; i++) {
            cnt[k][i] = (a[i] >> k & 1);
            cnt[k][i] += cnt[k][i-1];
        }
    }
    ll ans = 0;
    for(int k=0; k<=30; k++) {
        ll powk = (1ll << k);
        ll odd = 0, even = 1, tot = 0;
        for(int i=1; i<=n; i++) {
            if(cnt[k][i] % 2) {
                if(cnt[k][i-1] % 2 == 0) tot += even - 1;
                else tot += even;
                odd ++;
            } else {
                if(cnt[k][i-1] % 2 == 1) tot += odd - 1;
                else tot += odd;
                even ++;
            }
        }
        ans += tot * powk;
    }
    cout << ans << endl;
}

int main()
{
    int t=1;
    while(t --)
        solve();
    return 0;
}