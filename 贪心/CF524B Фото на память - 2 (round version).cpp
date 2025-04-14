#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool cmp(pii x, pii y) {
    return x.first > y.first;
}
int main() {
    int n; cin >> n;
    vector<pii> a(n + 1);
    for(int i=1; i<=n; i++) {
        int w, h; cin >> w >> h;
        a[i] = {max(w, h), min(w, h)};
    }
    sort(a.begin()+1, a.end(), cmp);
    int ans = 2e9;
    for(int i=1; i<=n; i++) { // 以a[i].first为最大宽
        int c = a[i].second, k = a[i].first;
        bool flg = 0;
        // cout << c << " " << k << endl;
        for(int j=1; j<=n; j++) {
            if(j == i) continue;
            if(a[j].first <= k) c += a[j].second;
            else {
                if(k < a[j].second) {
                    flg = 1;
                    break;
                }
                else {
                    c += a[j].first;
                }
            }
        }
        // cout << c << " " << k << endl << endl;
        if(!flg)
            ans = min(ans, c * k);
    }
    for(int i=1; i<=n; i++) { // 以a[i].first为最大宽
        int c = a[i].first, k = a[i].second;
        bool flg = 0;
        // cout << c << " " << k << endl;
        for(int j=1; j<=n; j++) {
            if(j == i) continue;
            if(a[j].first <= k) c += a[j].second;
            else {
                if(k < a[j].second) {
                    flg = 1;
                    break;
                }
                else {
                    c += a[j].first;
                }
            }
        }
        // cout << c << " " << k << endl << endl;
        if(!flg)
            ans = min(ans, c * k);
    }
    cout << ans << endl;
    return 0;
}