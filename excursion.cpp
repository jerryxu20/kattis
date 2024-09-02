#include <bits/stdc++.h>
using namespace std;

int main() {

    string s; cin >> s;

    long long ans = 0;
    vector<int> cnt(3);
    
    for (int i = 0; i < s.size(); i++) {
        int num = s[i] - '0';
        for (int j = num + 1; j < 3; j++) {
            ans += cnt[j];
        }
        cnt[num]++;
    }
    cout << ans << endl;
}