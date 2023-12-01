#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

int n, m;
map<string, int> card_id;
vi id;
vii hint_to_card, card_to_hint;
vector<ll> factorial(16, 1);
vector<vector<double>> dp;

ll ways(int n, int k) {
    return factorial[n] / factorial[n - k];
}

double f(int i, int player) {
    if (dp[i][player] >= 0) return dp[i][player];
    // the cards that are available tell me which hints are valid. 

    // then I try using every hint, with every count.
    // the players try guessing every order my hint indicates
    vii avail(2);
    vector<set<int>> hint(2);
    vii valid_guess_for_hint(m);
    int onboard = 0;
    vi max_on(m);
    for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) continue;
        int idx = id[j];
        if (idx == player) {
            onboard++;
        }
        trav(h, card_to_hint[j]) {
            valid_guess_for_hint[h].pb(j);
            if(idx == player) {
                hint[idx].insert(h);
                max_on[h]++;
            }
        }
    }

    // there are no cards of mine, so I win
    if (onboard == 0) {
        dp[i][player] = 1;
        return 1;
    }
    
    // iterate over valid hints for this player, 
    double best = 0;
    trav(h, hint[player]) {
        vi &guess = valid_guess_for_hint[h];

        vector<double> value(sz(guess) + 1);
        for (int ii = 1; ii < (1 << sz(guess)); ii++) {
            vi cards;
            for (int jj = 0; jj < sz(guess); jj++) {
                if (ii & (1 << jj)) cards.pb(guess[jj]);
            }
            // why is this max_on + 1? I think it should be > max_on.
            if (sz(cards) > max_on[h] + 1) continue;

            // the hint given is [h, sz(cards)]
            // try all orders we can do this guess in
            // which combo of [hint, sz] is the max expected]

            do {
                int state = i;
                bool lost = false;
                trav(card, cards) {
                    // lost
                    if (id[card] == -1) {
                        lost = true;
                        break;
                    }
                    // if I didn't immediately lose, I take this card
                    state &= ~(1 << card);
                    // this card is my teams card, I can keep going
                    if (id[card] == player) {
                        continue;
                    }
                    // this card was either opposite team or innocent, so the turn ended
                    break;
                }
                if (lost) continue;
                value[sz(cards)] += (1.0 - f(state, (player + 1) % 2)) / ways(sz(guess), sz(cards));
                best = max(value[sz(cards)], best);
            } while (next_permutation(all(cards)));
        }
    }
    // cout << bitset<4>(i).to_string() << " " << player<< ": " << best <<endl;
    dp[i][player] = best;
    return best;
}

int solve(int tt) { 
    
    char team;
    cin >> n >> team;
    string s;
    rep(i, 0, n) {
        cin >> s;
        card_id[s] = i;        
    }
    id.resize(n);
    
    char c;
    rep(i, 0, n) {
        cin >> c;
        if (c == 'B') id[i] = 1;
        else if (c == 'I') id[i] = -2;
        else if (c == 'A') id[i] = -1; 
    }

    cin >> m;

    hint_to_card.resize(m);
    card_to_hint.resize(n);
    rep(i, 0, m) {
        int x; cin >> x;
        while(x--) {
            cin >> s;
            int card = card_id[s];
            hint_to_card[i].pb(card);
            card_to_hint[card].pb(i);            
        }
    }

    dp.resize(1 << n, vector<double>(2, -1));
    cout << setprecision(20) <<  f((1 << n) - 1, team == 'B') << endl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    for (int i = 1; i < sz(factorial); i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}