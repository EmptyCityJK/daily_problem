    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main() {
        int n, m; cin >> n >> m;
        vector<ll> a(n + 1);
        for(int i=1; i<=n; i++)
            cin >> a[i];
        int num = sqrt(n);
        vector<ll> cnt(n + 1);
        while(m --) {
            int op; cin >> op;
            if(op == 1) {
                int x, y; cin >> x >> y;
                if(x <= num)
                    cnt[x] += y;
                else {
                    for(int i=x; i<=n; i+=x) {
                        a[i] += y;
                    }
                }
            }
            if(op == 2) {
                int idx; cin >> idx;
                if(idx == 0) {
                    cout << 0 << endl;
                } else {
                    ll delta = 0;
                    for(int i=1; i<=num; i++)
                        if(idx % i == 0)
                        delta += cnt[i];
                    cout << a[idx] + delta << endl;
                }

            }
        }
        return 0;
    }