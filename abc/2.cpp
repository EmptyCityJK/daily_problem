// 求一串数字的连续子串的和为奇数的个数（连续子串长度至少为2）
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
    int odd = 0, even = 1;
    for(int i=1; i<=n; i++) {
        if(a[i] & 1) {
            odd ++;
            if(a[i - 1] & 1 == 0) ans += even - 1;
            else ans += even;
        } else {
            even ++;
            if(a[i - 1] & 1) ans += odd - 1;
            else ans += odd;
        }
    }
    cout << ans << endl;
    return 0;
}