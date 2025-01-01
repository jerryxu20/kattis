#include <bits/stdc++.h>
using namespace std;

string s;
typedef long long ll;
const int MOD = 1e6 + 9;
const int MAXN = 1e6;
int dp[MAXN];

int vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int con(char c) {
    return !vowel(c);
}


int main() {
    cin >> s;

    vector<int> runs;
    int n = s.size();
    char prev = ' ';
    int run = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 2 && con(s[i]) && s[i] == s[i - 2] && s[i - 1] == 'o') {
            if (s[i] != prev && run) {
                runs.push_back(run);
                run = 0;
            }
            prev = s[i];
            run++;
            continue;
        }
        if (s[i] == 'o' && i > 0 && s[i - 1] == prev) continue;
        prev = ' ';
    }
    if (run) runs.push_back(run);

    ll ans = 1;
    for (int &x: runs) {
        if (x == 1) {
            ans *= 2;
            ans %= MOD;
            continue;
        }

        int l = (2 * x + 1);
        ans *= (l + 1)/4 + 1;
        ans %= MOD;
    }
    cout << ans << endl;
}