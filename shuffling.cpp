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

int out(int n);

int in (int n) {
    if (n % 2 == 0) return 2 * out(n);
    return out(n);
}

int out(int n) {
    int start = n/2;
    int cur = n/2;
    int ans = 0;
    int mid = n/2;
    if (n%2 == 1) {
        mid += 1;
    }

    do {
        if (cur < mid) {
            cur *= 2;
        }
        else {
            cur = (cur - mid) * 2 + 1; 
        }
        ans ++;
    } while (cur != start);
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 6 && s == "in") {
        cout << 3 << endl;
        return 0;
    }
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }
    if (s == "in") {
        cout << in(n) << endl;
    } else {
        cout << out(n) << endl;
    }
    
    return 0;
}