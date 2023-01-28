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
    int W, N;
    cin >> W >> N;
    ll area = 0;
    int w, l;
    while(N--) {
        cin >> w >> l;
        area += w * l;
    }
    cout << area / W << endl;
    return 0;
}