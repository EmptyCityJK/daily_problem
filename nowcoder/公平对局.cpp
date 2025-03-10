#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
inline void solve() {
    int n; cin >> n;
    vector<vector<char>> g(n + 5, vector<char>(n + 5));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> g[i][j];
        }
    }
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    vector<vector<bool> > vis(n + 5, vector<bool>(n + 5));
    map<pii, int> mp;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(vis[i][j]) continue;
            if(g[i][j] == '*') {
                vis[i][j] = 1;
                int tot = 1;
                queue<pii> q;
                set<pii> st;
                q.push({i, j});
                while(q.size()) {
                    auto [x, y] = q.front(); q.pop();
                    for(int i=0; i<4; i++) {
                        int xx = x + dx[i], yy = y + dy[i];
                        if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
                        if(g[xx][yy] == '.') st.insert({xx, yy});
                        if(vis[xx][yy]) continue;
                        vis[xx][yy] = 1;    
                        if(g[xx][yy] == '*') q.push({xx, yy}), tot ++;
                    }
                }
                if(st.size() == 1) {
                    mp[*st.begin()] += tot;
                }
            }
        }
    }
    int ans = 0;
    for(auto t: mp) {
        ans = max(ans, t.second);
    }
    cout << ans << endl;
}
 
int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}