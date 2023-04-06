#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
    int W, S, C, K;
    cin >> W >> S >> C >> K;
    if (K == 0) {
        cout << "NO\n";
        return 0;
    }
    int a = S;
    int b = W + C;
    bool first = a <= K && b <= 2 * K;
    bool second = a <= 2 * K && b <= K;
    bool third = a < K || b < K;
    if (first || second || third) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}