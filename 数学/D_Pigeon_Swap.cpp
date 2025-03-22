#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// 求pos[id[a]]
inline void solve() {
    int n, q; cin >> n >> q;
    vector<int> id(n + 1); //第i只鸟所在的鸟巢编号
    vector<int> pos(n + 1); //第i个鸟巢所处的地上位置编号
    vector<int> npos(n + 1); //pos的反向映射，npos[i]记录位置i上的鸟巢位置
    for(int i=1; i<=n; i++)
        id[i] = i;
    pos = npos = id;
    while(q --) {
        int t; cin >> t;
        int a, b;
        if(t == 1) {//一只鸟从位置a移到位置b
            cin >> a >> b;
            id[a] = npos[b];
        }
        else if(t == 2) {//a <-> b
            cin >> a >> b;
            swap(pos[npos[a]], pos[npos[b]]);
            swap(npos[a], npos[b]);
        }
        else {
            cin >> a;
            cout << pos[id[a]] << endl;
        }
    }
}

int main()
{
    int t = 1;
    while(t --)
        solve();
    return 0;
}