#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a.begin()+1, a.begin()+1+n);
    auto check = [&] (int m, int i) {
        int dif = abs(a[m] - a[i]);
        if(dif <= k) return true;
        return false;
    };
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int l = i, r = n;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(mid, i)) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l - i + 1);
    }
    cout << ans << endl;
    return 0;
}