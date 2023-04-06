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
    int n;
    cin >> n;
    vi cards(n);
    for (auto &x: cards) cin >> x;
    // score is the sum of numbers on cards
    // if two or more consecutive nums, only smallest num counts
    cards.pb(100000);
    sort(all(cards));
    int low = 0;
    int ans = 0;
    for (int i = 1; i < sz(cards); i++) {
        if (cards[i] == cards[i - 1] + 1) continue;
        ans += cards[low];
        low = i;
    }
    cout << ans << endl;
    return 0;
}