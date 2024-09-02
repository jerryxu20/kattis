#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int j = 0; j <= n; j++) cout << " ";
    cout << "x\n";
    int cur = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << " ";
        cout << "/";
        for (int j = 0; j < cur; j++) cout << " ";
        cout << "\\\n";
        cur += 2;
    }
    cout << "x";
    for (int j = 0; j < cur; j++) cout << " ";
    cout << "x\n";
    cur -= 2;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) cout << " ";
        cout << "\\";
        for (int j = 0; j < cur; j++) cout << " ";
        cout << "/\n";
        cur -= 2;
    }
    for (int j = 0; j <= n; j++) cout << " ";
    cout << "x\n";

}