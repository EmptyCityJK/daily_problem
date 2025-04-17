#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> mp(n + 1);
    for(int i=1; i<=n; i++) {
        string s; cin >> s;
        mp[i] = s;
    }
    int k, cnt = 0; cin >> k;
    getchar(); 
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> ans;
    while(ss >> s) {
        for(int k=1; k<=n; k++) {
            string t = mp[k];
            int len = t.size();
            for(int i=0; i<(int)s.size(); i++) {
                for(int j=1; j<=min((int)s.size(), len); j++) {
                    if(t == s.substr(i, j)) {
                        cnt ++;
                        s.replace(i, j, "<censored>");
                        i += 9;
                    }
                }
            }
        }
        ans.push_back(s);
    }
    if(cnt >= k) {
        cout << cnt << endl;
        puts("He Xie Ni Quan Jia!");
    } else {
        int len = ans.size();
        for(int i=0; i<len-1; i++)
            cout << ans[i] << " ";
        cout << ans[len-1];
    }
    return 0;
}