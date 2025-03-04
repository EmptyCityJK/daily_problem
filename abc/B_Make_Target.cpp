#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline void solve() {
    int n; cin >> n;
    vector<vector<char>> g(n + 1, vector<char>(n + 1));
    for(int i=1; i<=(n+1)/2; i++) {
        int cnt = 0;
        for(int j=1; j<=i; j++) {
            if(cnt % 2 == 0) {
                g[i][j] = '#';
            } else g[i][j] = '.';
            cnt ++;
            // cout << g[i][j];
        }
        // cout << endl;
    }
    for(int i=1; i<=(n+1)/2; i++) {
        int cnt = 0;
        for(int j=n; j>=(n-i+1); j--) {
            if(cnt % 2 == 0) g[i][j] = '#';
            else g[i][j] = '.';
            cnt ++;
        }
    }
    for(int i=1; i<=n; i++) {
        char c = g[i][i];
        for(int j=i+1; j<=(n-i); j++) {
            g[i][j] = c;
        }
    }
    for(int i=n; i>(n+1)/2; i--) {
        g[i] = g[n - i + 1];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << g[i][j];
        cout << endl;
    }
}

int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}