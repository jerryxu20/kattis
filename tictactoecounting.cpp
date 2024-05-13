#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef pair<long long, long long> pi;

map<string, pi> dp[26];

bool win(const string &s, char c) {
    int ans = 0;
    for (int i = 0; i + 2 < 9; i += 3) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == c) ans++;
    }
    for (int i = 0; i < 3; i++) {
        if (s[i] == s[i + 3] && s[i] == s[i + 6] && s[i] == c) ans++;
    }

    if (s[0] == s[4] && s[0] == s[8] && s[0] == c) ans++;
    if (s[2] == s[4] && s[2] == s[6] && s[2] == c) ans++;
    return ans;
}


bool valid(string &s) {
    if (win(s, 'X') && win(s, 'O')) return false;

    if (win(s, 'X') + win(s, 'O') > 1) return false;
    
    
    int a = count(all(s), 'X');
    int b = count(all(s), 'O');

    if (b > a) return false;
    if (a > b + 1) return false;

    if (win(s, 'X') && a == b) return false;
    if (win(s, 'O') && b < a) return false;

    return true;
}

string st = ".OX";

pi backtrack(string &s, char c) {
    char nxt = 'X';
    if (c == 'X') nxt = 'O';

    if (dp[c - 'A'].count(s)) return dp[c - 'A'][s];
    

    if (win(s, 'X') && win(s, 'O')) {
        assert(false);
        dp[c - 'A'][s] = {0, 0};
        return {0, 0};
    }

    if (win(s, nxt)) {
        dp[c - 'A'][s] = {0, 1};
        return {0, 1};
    }
    
    pi ans = {0, 0};
    for (int i = 0; i < 9; i++) if (s[i] == '.') {
        s[i] = c;
        pi cand = backtrack(s, nxt);
        ans.first += cand.second;
        ans.second += cand.first;
        s[i] = '.';
    }
    dp[c - 'A'][s] = ans;
    return ans;


    
}

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;

        if (!valid(s)) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        int a = count(all(s), 'X');
        int b = count(all(s), 'O');

        if (a == b) {
            pi ans = backtrack(s, 'X');
            cout << ans.first << " " << ans.second << endl;
        } else {
            pi ans = backtrack(s, 'O');
            cout << ans.second << " " << ans.first << endl;
            
        }
        
    }
}