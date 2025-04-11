#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, m; cin >> n >> q >> m;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<array<int, 3>> v;
    while(q -- ) {
        int op, l, r; cin >> op >> l >> r;
        v.push_back({op, l, r});
    }
    q = v.size();
    for(int i=1; i<=m; i++) {
        int idx; cin >> idx;
        for(int j=q; j>=0; j--) {
            auto [op, l, r] = v[j];
            if(l > idx || idx > r) continue;
            if(op == 1) { // 循环左移
                idx = idx - 1;
                if(idx == l-1) idx = r;
            }
            if(op == 2) { // 反转
                idx = r - (idx - l);
            }
        }
        cout << a[idx] << " ";
    }
    return 0;
}