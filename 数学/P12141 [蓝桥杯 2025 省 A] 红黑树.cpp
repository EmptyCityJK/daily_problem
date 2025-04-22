#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;
    while(m --) {
        int n, k; cin >> n >> k;
        // 0 红 1 黑
        // 1. 左半部分与上一层一样
        // 2. 右半部分与上一层相反
        // -> k 的颜色与 k-1 的二进制表示的1的个数奇偶有关
        // if(__builtin_parity(k-1)) cout << "BLACK" << endl; // 奇数个1
        // else cout << "RED" << endl; // 偶数个1
        auto bi = [&](int n) {
            int res = 0;
            for(int i=0; i<=30; i++) {
                if(n >> i & 1) res ++;
            }
            return res;
        };
        int num = bi(k-1);
        if(num & 1) puts("BLACK");
        else puts("RED");
    }
    return 0;
}