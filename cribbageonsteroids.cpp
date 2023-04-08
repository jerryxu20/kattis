#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

ll fifteen(vector<ll> &cards) {
    vector<ll> dp(16);
    dp[0] = 1;
    for (auto &card: cards) {
        // if I use this card, how many ways can I make 15
        for (ll i = 15; i >= card; i--) {
            dp[i] += dp[i - card];
        }
    }
    return dp.back() * 2;
}

ll pairs(map<char, ll> &freq) {
    ll ans = 0;
    for (auto &[card, f]: freq) {
        ans += (f * (f - 1)) / 2;
    }
    return ans * 2;
}

ll runs(map<char, ll> &freq) {
    char prev = ' ';
    ll cur = 1;
    ll run = 0;
    ll ans = 0;
    for (auto &[card, f]: freq) {
        if (prev + 1 == card) {
            run++;
            cur *= f;
            prev = card;
            continue;
        }
        if (run >= 3) {
            ans += cur * run;
        }
        cur = f;
        run = 1;
        prev = card;
    }
    if (run >= 3) ans += cur * run;
    return ans;
}


int main() {
    ll n;
    cin >> n;
    map<char, ll> values = {
        {'A', 1},
        {'T', 10},
        {'J', 10},
        {'Q', 10},
        {'K', 10},
    };
    map<char, char> order = {
        {'A', 'A'},
        {'T', 'J'},
        {'J', 'K'},
        {'Q', 'L'},
        {'K', 'M'},
    };
    vector<ll> cards(n);
    map<char, ll> freq;
    char a;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        if (values.count(a)) {
            cards[i] = values[a];
            freq[order[a]]++;
        } else {
            cards[i] = a - '0';
            freq[a - '1' + 'A']++;
        } 
    }
    // cout << "fifteen " << fifteen(cards) << endl;
    // cout << "pairs " << pairs(freq) << endl;
    // cout << "runs " << runs(freq) << endl;
    // for (auto &card: cards) {
    //     cout << card << " ";
    // }
    // for (auto &[cat, f]: freq) {
    //     cout << cat << " " << f << endl;
    // }
    // cout << endl;
    cout << fifteen(cards) + pairs(freq) + runs(freq) << endl;
    // forward left right
    // what is the min number of forwards to get bot robots out of maze
    return 0;
}