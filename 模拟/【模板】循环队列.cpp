#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    int front = 0, tail = 0;
    int sz = n + 1; // 多开一格 -> 方便判断循环队列是否已满
    while(q -- ) {
        string s; cin >> s;
        if(s == "push") {
            int m; cin >> m;
            if((tail + 1) % sz == front)
                puts("full");
            else {
                a[tail] = m;
                tail = (tail + 1) % sz;
            }
        } else {
            if(front == tail) 
                puts("empty");
            else {
                cout << a[front] << endl;
                if(s == "pop") {
                    front = (front + 1 + sz) % sz;
                }
            }
        }
    }
    return 0;
}