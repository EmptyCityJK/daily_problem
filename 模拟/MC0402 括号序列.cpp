#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

inline void solve() {
    string s; cin >> s;
    int n = s.size();
    ll ans = 0, l = 0, r = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') {
            if(r) {
                ans += r;
                r --;
            } else l ++;
        } else {
            if(l) l --;
            else r ++;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while(t --)
        solve();
    return 0;
}