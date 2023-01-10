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
    int a, b;
    double c, d;
    while (cin >> a >> b >> c >> d) {
        if (abs(c - d) >= 10e-7) {
            cout << a << " " << b << endl;
            cout << c << " " << d << endl;
            break;
        }
    };
    return 0;
}