#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    int h, w; cin >> h >> w;
    vector<vector<int>> g(h + 1, vector<int>(w + 1));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> vis(h + 1, vector<int> (w + 1, 0));
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    vector<pii> ans; bool flg = 0;
    ans.push_back({0, 0}); vis[0][0] = 1;
    function<void(int, int, vector<pii>)> dfs = [&](int x, int y, vector<pii> res) {
        if(x == h-1 && y == w-1) {
            flg = 1;
            ans = res;
            return ;
        }
        for(int i=0; i<4; i++) {
            if(flg) return ;
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || xx >= h || yy < 0 || yy >= w || g[xx][yy] || vis[xx][yy]) continue;
            res.push_back({xx, yy});
            vis[xx][yy] = 1;
            dfs(xx, yy, res);
            if(flg) return ;
            res.pop_back();
            vis[xx][yy] = 0;
        }
    };
    dfs(0, 0, ans);
    // cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        printf("(%d,%d)\n", ans[i].first, ans[i].second);
    }
    return 0;
}