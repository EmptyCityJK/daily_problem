#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> post(n + 1);
    for(int i=1; i<=n; i++) {
        cin >> post[i];
    }
    int id = 1;
    vector<int> tree(n + 1);
    function<void(int)> dfs = [&] (int r) {
        if(r > n) return ;
        dfs(2 * r); // 左
        dfs(2 * r + 1); // 右
        tree[r] = post[id ++]; // 根
    };
    dfs(1);
    for(int i=1; i<n; i++) {
        cout << tree[i] << " ";
    }
    cout << tree[n];
}