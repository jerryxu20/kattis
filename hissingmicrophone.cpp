#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 's' && s[i - 1] == 's') {
            cout << "hiss";
            return 0;
        }
    }
    cout << "no hiss";
    return 0;
}