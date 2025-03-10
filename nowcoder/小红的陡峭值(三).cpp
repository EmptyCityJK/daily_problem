#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> pre(n + 1, 0);
    for(int i=1; i<n; i++) {
        pre[i] = pre[i - 1] + abs(s[i] - s[i - 1]);
    }
    // for(int i=1; i<n; i++) cout << pre[i] << " ";
    // cout << endl;
    ll tot = 0;
    for(int i=k-1; i<n; i++) {
        tot += pre[i] - pre[i - k + 1];
    }
    cout << tot << endl;
    return 0;
}