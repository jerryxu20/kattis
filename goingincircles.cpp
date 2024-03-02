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

long long rand(long long a, long long b) {
    return a + rand() % (b - a + 1);
}

int solve(int tt) {
    srand(time(0));
    int n = 0;
    int x;
    int moves = 0;

    cin >> x;
    // make first pos white
    if (x == 1) {
        moves++;
        cout << "? flip" << endl;
        cin >> x;
    }
    

    
    // this should test for lengths < 100
    while(n < 32) {
        n++;
        moves++;
        cout << "? left" << endl;
        cin >> x;

        // test if n is the correct length
        while (x == 0 && n < 32) {
            moves++;
            cout << "? flip" << endl;
            cin >> x;
            // if I go left by n, it should be all black including last tile. 
            // if not, I can consider testing another length
            int len = n;
            rep(j, 0, len) {
                moves++;
                n++;
                cout << "? left" << endl;
                cin >> x;
                
                if (x == 0) break;
            }

            // there was a light square n to the left, meaning our original len was wrong
            // and we should continue testing from this point
            if (x == 0) continue;
            
            // it was entirely a run of black squares, len might be correct
            // to test, we will flip and then turn back
            moves++;

            cout << "? flip" << endl;
            cin >> x;

            rep(j, 0, len) {
                moves++;
                cout << "? right" << endl;
                cin >> x;
            }

            // we turned back and got a white square
            // so this was the correct length
            if (x == 0) {
                assert(moves <= 3 * len + 500);
                
                cout << "! " << len << endl;
                return 0;
            }


            // this was wrong, so go forward again. 
            rep(j, 0, len) {
                moves++;
                cout << "? left" << endl;
                cin >> x;
            }

            assert(x == 0);

            // unflip the test square
            moves++;
            cout << "? flip" << endl;
            cin >> x;
        }
    }



    int pattern = 9084532;
    rep(i, 0, 31) {
        int bit = 0;
        if (pattern & (1 << i)) bit = 1;
        if (x != bit) {
            cout << "? flip" << endl;
            cin >> x;
        }

        cout << "? left" << endl;
        cin >> x;
    }

    // set the first 31 bits to this, then see when it comes up again
    int last = pattern;
    n = 0;
    while(true) {
        n++;
        cout << "? left" << endl;
        cin >> x;
        last >>= 1;
        if (x) {
            last += (1 << 30);
        }
        
        if (last == pattern) {
            cout << "! " << n + 1 << endl;
            return 0;
        }
        

    }


    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}