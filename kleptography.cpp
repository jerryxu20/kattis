#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int n, m;
    cin >> n >> m;
    string last_part, cipher;
    cin >> last_part >> cipher;
    vector<int> plain(m);
    for (int i = m - n; i < m; i++) {
        plain[i] = last_part[i - (m - n)] - 'a';
    }
    for (int i = m - 1 - n; i >= 0; i--) {
        plain[i] = ((cipher[i + n] - 'a' - plain[i + n]) % 26 + 26) % 26;
    }
    for (int &c: plain) {
        cout << char(c + 'a');
    }
    cout << endl;
    return 0;
}