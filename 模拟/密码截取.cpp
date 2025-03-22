#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    // i为偶 -> 奇回文串；i为奇 -> 偶回文串
    for(int i=1; i<(n - 1) * 2; i++) {
        if(i % 2) { // 回文中心：在两个字符中间
            int j = i / 2;
            int tot = 0;
            for(int l=j, r=j+1; l>=0 && r<n; l--, r++) {
                if(s[l] == s[r]) tot ++;
                else break;
            }
            ans = max(ans, tot * 2);
        } else {
            int j = i / 2;
            int tot = 1;
            for(int l=j-1, r=j+1; l>=0 && r<n; l--, r++) {
                if(s[l] == s[r]) tot += 2;
                else break;
            }
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}