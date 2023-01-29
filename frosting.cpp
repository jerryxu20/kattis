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
    // color(i, j) = (i + j) % 3;
    ll n, a;
    cin >> n;
    vector<ll> row(3);
    vector<ll> col(3);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        row[i % 3] += a; 
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        col[i % 3] += a; 
    }
    vector<ll> colors(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            colors[(i + j) % 3] += row[i] * col[j];
        }
    }
    for (auto color: colors) {
        cout << color << " ";
    }
    cout << endl;
    return 0;
}