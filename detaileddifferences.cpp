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
    int t;
    cin >> t;
    string a;
    string b;
    int n;
    while (t--) {
        cin >> a;
        cin >> b;
        n = a.length();
        cout << a << endl;
        cout << b << endl;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cout << '.';
            } else {
                cout << '*';
            }
        }
        cout << "\n\n";
    }
}