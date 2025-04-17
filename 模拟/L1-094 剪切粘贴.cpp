#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    s = " " + s;
    int n; cin >> n;
    while(n -- )
    {
        int st, ed; cin >> st >> ed;
        int d = ed - st + 1;
        string s1, s2; cin >> s1 >> s2;
        int len1 = s1.size(), len2 = s2.size();
        string t = s.substr(st, d);
        s.erase(st, d);
        int len = s.size()-1;
        bool flg = false;
        for(int i=1; i+len1-1<=len; i++) {
            if(s.substr(i, len1) == s1) {
                if(s.substr(i+len1, len2) == s2) {
                    s.insert(i+len1, t);
                    flg = true;
                    break;
                }
            }
        }
        if(!flg) s += t;
    }
    for(int i=1; i<=s.size()-1; i++) {
        cout << s[i];
    }
    return 0;
}