// 256进制转10进制 && 10进制转256进制
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string a; ll b; cin >> a >> b;
    int n = a.size();
    ll ans = 0; ll t = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == '.') {
            ans = ans * 256 + t;
            t = 0;
            continue;
        }
        t = t * 10 + a[i] - '0';
    }
    ans = ans * 256 + t;
    int res[4]; int i = 0;
    while(b) {
        res[i ++] = b % 256;
        b /= 256;
    }
    cout << ans << endl;
    printf("%d.%d.%d.%d", res[3], res[2], res[1], res[0]);
}
