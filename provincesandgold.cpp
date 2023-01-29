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
    int g, s, c;
    cin >> g >> s >> c;
    int points = g * 3 + s * 2 + c * 1;
    vector<string> ans;
    if (points >= 8) {
        ans.push_back("Province");
    } else if (points >= 5) {
        ans.push_back("Duchy");
    } else if (points >= 2) {
        ans.push_back("Estate");
    }

    if (points >= 6) {
        ans.push_back("Gold");
    } else if (points >= 3) {
        ans.push_back("Silver");
    } else {
        ans.push_back("Copper");
    }
    cout << ans[0] << " ";
    if (sz(ans) > 1) {
        cout << "or " << ans[1];
    }
    cout << endl;

    // what is the best vicotry card, and the best treasure card jake can buy this turn
    return 0;
}