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
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        double ans = n / 400.0;
        cout << ceil(ans) << endl;
    }
    return 0;
}