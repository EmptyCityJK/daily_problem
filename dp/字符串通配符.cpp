    #include <bits/stdc++.h>
    #include <vector>
    using namespace std;
    inline bool isUpper(char n) {
        return (n >= 'A' && n <= 'Z');
    }
    inline bool isLower(char n) {
        return (n >= 'a' && n <= 'z');
    }
    inline bool isZimu(char n) {
        return isUpper(n) || isLower(n);
    }
    inline bool isNum(char n) {
        return (n >= '0' && n <= '9');
    }
    inline bool check(char n) {
        return isNum(n) || isZimu(n);
    }
    int main() {
        string s, p; cin >> s >> p;
        int n = s.size(), m = p.size();
        // dp[i][j]: s[0-i-1] 和 p[0-j-1] 之间能否匹配
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        // p为空串时，只有s全为*才为true
        for(int i=0; i<n; i++) {
            if(s[i] != '*') break;
            dp[i + 1][0] = true;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                // s[0~i-1]匹配p[0~j-2的]情况(插入多个) or s[0~i-2]匹配p[0~j-1]的情况(不插)
                if(s[i-1] == '*' && check(p[j-1])) dp[i][j] = dp[i][j-1] | dp[i-1][j] | dp[i-1][j-1];
                else if(s[i-1] == '?' && check(p[j-1])) dp[i][j] = dp[i-1][j-1];
                else if(tolower(s[i-1]) == tolower(p[j-1])) dp[i][j] = dp[i-1][j-1]; 
            }
        }
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=m; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        if(dp[n][m]) cout << "true" << endl;
        else cout << "false" << endl;
    }