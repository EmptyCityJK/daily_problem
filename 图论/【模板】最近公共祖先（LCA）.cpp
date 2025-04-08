#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, s; cin >> n >> q >> s;
    vector<int> g[n + 1];
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 询问a结点和b结点的最近公共祖先
    while(q -- ) {
        int a, b; cin >> a >> b;
    }
    return 0;
}