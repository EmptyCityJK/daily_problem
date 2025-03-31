#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<pii> a(n + 1);
    int maxn = 0;
    for(int i=1; i<=n; i++) {
        int u, v; cin >> u >> v;
        a[i] = {u, v};
    }
    auto cmp = [&](pii x, pii y) {
        return x.second < y.second;
    };
    // 按结束时间从小到大排序
    sort(a.begin()+1, a.begin()+1+n, cmp);
    int ans = 0;
    int ed = -1;
    for(int i=1; i<=n; i++) {
        if(a[i].first >= ed) {
            ans ++;
            ed = a[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}