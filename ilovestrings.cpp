#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const char nl = '\n';

const int MAXN = 1e5;
const int V = 10;
const int C = 42;

typedef long long ll;
ll LEFT_CNT[MAXN][V][C], RIGHT_CNT[MAXN][V][C];
ll PREF_V[MAXN][V], PREF_C[MAXN][C], TOT[MAXN];
ll CNT_C[C], CNT_V[V];

string vowels = "AEIOUaeiou";
string constanants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
int vid(char c) {
    return lower_bound(vowels.begin(), vowels.end(), c) - vowels.begin();
}

int cid(char c) {
    return lower_bound(constanants.begin(), constanants.end(), c) - constanants.begin();
}

bool vowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main() {
    sort(vowels.begin(), vowels.end());
    sort(constanants.begin(), constanants.end());


    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < V; v++) {
            for (int c = 0; c < C; c++) {
                if (i > 0) {
                    LEFT_CNT[i][v][c] += LEFT_CNT[i - 1][v][c]; 
                    LEFT_CNT[i][v][c] %= MOD;
                }
            }
        }
        if (i > 0) {
            TOT[i] += TOT[i - 1];
        }

        for (int v = 0; v < V; v++) {
            if (i > 0) {
                PREF_V[i][v] += PREF_V[i - 1][v];
                PREF_V[i][v] %= MOD;
            }
        }
        for (int c = 0; c < C; c++) {
            if (i > 0) {
                PREF_C[i][c] += PREF_C[i - 1][c];
                PREF_C[i][c] %= MOD;
            }
        }

        // if I am a vowel
        if (vowel(s[i])) {
            int v = vid(s[i]);
            CNT_V[v]++;
        } else {
            int c = cid(s[i]);
            for (int v = 0; v < V; v++) {
                LEFT_CNT[i][v][c] += CNT_V[v];
                PREF_C[i][c] += CNT_V[v];
                PREF_V[i][v] += CNT_V[v];
                TOT[i] += CNT_V[v];

                LEFT_CNT[i][v][c] %= MOD;
                PREF_C[i][c] %= MOD;
                PREF_V[i][v] %= MOD;
                TOT[i] %= MOD;
            }
        }
        
    }

    memset(CNT_V, 0, sizeof(CNT_V));
    for (int i = n - 1; i >= 0; i--) {
        for (int v = 0; v < V; v++) {
            for (int c = 0; c < C; c++) {
                if (i < n - 1) {
                    RIGHT_CNT[i][v][c] += RIGHT_CNT[i + 1][v][c]; 
                    RIGHT_CNT[i][v][c] %= MOD;
                }
            }
        }


        // if I am a vowel
        if (vowel(s[i])) {
            int v = vid(s[i]);
            CNT_V[v]++;
        } else {
            int c = cid(s[i]);
            for (int v = 0; v < V; v++) {
                RIGHT_CNT[i][v][c] += CNT_V[v];
                RIGHT_CNT[i][v][c] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i + 1 < n; i++) if (vowel(s[i])) {
        int v1 = vid(s[i]);
        for (int v2 = 0; v2 < V; v2++) {
            for (int c = 0; c < C; c++) if (v1 != v2) {
                ll cnt = RIGHT_CNT[i + 1][v2][c];
  
                ll left = TOT[i - 1];
                left -= PREF_V[i - 1][v1];
                left -= PREF_V[i - 1][v2];
                left -= PREF_C[i - 1][c];
                left += LEFT_CNT[i - 1][v1][c];
                left += LEFT_CNT[i - 1][v2][c];
                left %= MOD;
                ans += (left * cnt) % MOD;
                ans %= MOD;
            }
        }

    }
    
    cout << ((ans % MOD) + MOD) % MOD << endl;
}