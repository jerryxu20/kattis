#include <bits/stdc++.h>
using namespace std;


int main() {
    int h;
    string s = "";
    cin >> h;
    h += 1;
    while (cin >> s) {
        continue;
    }
    int n = 1 << h;
    vector<int> tree(n);
    int num = 1;
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = num++;
    }
    int idx = 1;
    for (char c: s) {
        if (c == 'L') {
            idx = idx * 2;
        } else {
            idx = idx * 2 + 1;
        }
    }
    cout << tree[idx];
    return 0;
}