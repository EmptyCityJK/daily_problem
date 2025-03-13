#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    int x = 0, y = 0;
    char c; int num = 0;
    bool flg = 0;
    for(int i=0; i<n; i++) {
        if(cnt == 0 && s[i] != ';') c = s[i], cnt ++;
        else if(s[i] != ';') {
            if(s[i] < '0' || s[i] > '9' || flg) {
                flg = 1; num = 0; continue;
            }
            if(cnt == 1) {
                num = s[i] - '0';
            } else if(cnt == 2) {
                num = num * 10 + s[i] - '0';
            } else {
                flg = 1;
            } 
            cnt ++;
            // cout << c << " " << num << " " << flg << endl;
        } else if(s[i] == ';'){
            if(flg) {
                num = 0; cnt = 0; c = '*', flg = 0;
                continue;
            }
            if(c == 'W' && num != 0) {
                y += num;
                num = 0; cnt = 0; c = '*', flg = 0;
            } else if(c == 'A' && num != 0) {
                x -= num;
                num = 0; cnt = 0; c = '*', flg = 0;
            } else if(c == 'S' && num != 0) {
                y -= num;
                num = 0; cnt = 0; c = '*', flg = 0;
            } else if(c == 'D' && num != 0) {
                x += num;
                num = 0; cnt = 0; c = '*', flg = 0;
            } else {
                num = 0; cnt = 0; c = '*', flg = 0;
            }
            // cout << x << " " << y << endl;
        }
    }
    cout << x << "," << y << endl;
    return 0;
} 