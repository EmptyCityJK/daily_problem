#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    int n, m, s; cin >> n >> m >> s;
    vector<pii> g[n + 1];
    for(int i=1; i<=m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    auto dijktsra = [&](int r) {
        vector<int> dis(n + 1, 2e9);
        vector<bool> st(n + 1);
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        heap.push({0, r});
        dis[r] = 0;
        while(heap.size()) {
            auto [d, u] = heap.top(); heap.pop();
            if(st[u]) continue;
            st[u] = 1;
            for(auto [v, w]: g[u]) {
                if(dis[v] > d + w) {
                    dis[v] = d + w;
                    heap.push({dis[v], v});
                }
            }
        }
        return dis;
    };
    auto d = dijktsra(s);
    for(int i=1; i<d.size(); i++) {
        cout << d[i] << " ";
    }
    return 0;
} 