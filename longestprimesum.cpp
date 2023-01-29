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
    ll N;
    cin >> N;
    ll ans = 0;
    if (N % 2 == 1) {
        ans++;
        N -= 3;
    }
    ans += N/2;
    cout << ans << endl;
    // max number of sums to create n
    
    return 0;
}