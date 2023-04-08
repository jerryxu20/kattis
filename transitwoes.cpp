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
    int s, t, n;
    cin >> s >> t >> n;
    vector<int> walk(n + 1);
    vector<int> bus(n);
    vector<int> interval(n);
    int time = s;
    for (auto &w: walk) {
        cin >> w;
    }
    for (auto &x: bus) {
        cin >> x;
    }
    for (auto &x: interval) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        time += walk[i];
        int c = interval[i];
        if (time % c != 0) {
            int d = ceil((double)time / c);
            time = d * c;
        }
        time += bus[i];
    }
    time += walk.back();
    if (time <= t) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    
    return 0;
}