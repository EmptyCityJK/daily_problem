#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i=1; i<=n; i++) {
        ll x;
        cin >> x;
        q.push(x);
    }
    ll ans = 0;
    while(q.size() > 1) {
        ll u = q.top(); q.pop();
        ll v = q.top(); q.pop();
        q.push(u+v);
        ans += u+v;
    }
    cout << ans << endl;
    return 0;
}