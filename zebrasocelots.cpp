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
    int N;
    cin >> N;
    bitset<70> animals;
    char c;
    for (int i = N - 1; i >= 0; i--) {
        cin >> c;
        if (c == 'O') {
            animals[i] = true;
        }
    }
    auto ans = animals.to_ullong();
    cout << ans << endl;
    return 0;
}