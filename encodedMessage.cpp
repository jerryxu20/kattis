#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int r = sqrt(s.length());
        vector<string> ans(r);
        for (int j = 0; j < s.length(); j++) {
            ans[j % r] += s[j];
        }
        for (int j = r - 1; j >= 0; j--) {
            cout << ans[j];
        }
        cout << endl;
    }
    return 0;
}