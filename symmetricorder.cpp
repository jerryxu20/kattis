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
    int test = 1;
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> close;
        vector<string> far;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (i % 2 == 0) {
                close.pb(s);
            } else {
                far.pb(s);
            }
        }
        cout << "SET " << test << "\n"; 
        for (string &st: close) {
            cout << st << "\n";
        }
        reverse(all(far));
        for (string &st: far) {
            cout << st << "\n";
        }
        test++;
    }
    return 0;
}