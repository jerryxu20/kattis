#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= c; i++) {
        string ans = "";
        if (i % a == 0) {
            ans += "Fizz";
        }
        if (i % b == 0) {
            ans += "Buzz";
        }
        if (ans.length() == 0) {
            cout << i << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
