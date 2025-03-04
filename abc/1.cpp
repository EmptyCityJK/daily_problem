// 求一串数字的连续子串的和为奇数的个数(一个数字也是连续子串)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++) {
        int t; cin >> t;
        a[i] = a[i - 1] + t;
    }
    int ans = 0;
    int odd = 0, even = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] & 1) {
            odd ++;
            ans += even + 1;
        } else {
            even ++;
            ans += odd;
        }
    }
    cout << ans << endl;
    return 0;
}