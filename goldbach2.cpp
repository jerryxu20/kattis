#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

#define pb push_back
#define mp make_pair
vi primes;
// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void sieve(vi &ans) {
    vector<bool> is_prime(100000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= 32000; i++) {
        if (!is_prime[i]) continue;
        //mark primes
        ans.pb(i);
        for (int j = i * i; j < 100000; j += i) {
            is_prime[j] = false;
        }
    } 
    return;
}

int solve(int tcase) {
    int x;
    cin >> x;
    int low = 0;
    int high = sz(primes) - 1;
    vpii ans;    
    while (low <= high) {
        if (primes[low] + primes[high] > x) {
            high--;
        } else if (primes[low] + primes[high] < x) {
            low++;
        } else {
            ans.pb(mp(primes[low], primes[high]));
            low++;
        }
    }
    cout << x << " has " << sz(ans) << " representation(s)\n";
    for (auto &[a, b]: ans) {
        cout << a << "+" << b << endl;
    }
    cout << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    sieve(primes);
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}