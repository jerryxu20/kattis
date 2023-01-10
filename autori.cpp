#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (char c: s) {
        if (isupper(c)) {
            ans += c;
        }
    }
    cout << ans;
    
    return 0;
}