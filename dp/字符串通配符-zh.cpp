#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    int ls = s.size(), lp = p.size();
    vector<vector<int>> dp(ls+1, vector<int>(lp+1));
    for(int i=0; i<=ls; i++) {
        if(i >= 1 && s[i-1] == '*') {
            dp[i][0] = dp[i-1][0];
        } else {
            if(i >= 1) dp[i][0] = dp[i-1][0] + 1;
            else dp[i][0] = 0;
        }
        
    }
    for(int j=0; j<=lp; j++)
        dp[0][j] = j;
    auto check = [&](char x) {
        if(x >= '0' && x <= '9') return 1;
        if(x >= 'A' && x <= 'Z') return 2;
        if(x >= 'a' && x <= 'z') return 3;
        return 0;
    };
    for(int i=1; i<=ls; i++) {
        for(int j=1; j<=lp; j++) {
            if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                if(check(s[i-1]) + check(p[i-1]) == 5 && abs(s[i-1]-p[j-1]) == 32) {
                   dp[i][j] = dp[i-1][j-1];
                } else if(check(s[i-1])) {
                    dp[i][j] = 1;
                } else if(check(p[j-1])) {
                    if(s[i-1] == '*') {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    } else if(s[i-1] == '?') {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = 1;
                }
            }
        }
    }
    if(dp[ls][lp] == 0) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
