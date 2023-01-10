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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> times(n);
        for (int i = 0; i < n; i++) {
            int w;
            cin >> w;
            while (w--) {
                int a;
                cin >> a;
                times[i] += a;
            }
        }
        int running = 0;
        ll top = 0;
        sort(all(times));
        for (int time: times) {
            running += time;
            top += running;
        }
        double ans = top / double(n);
        cout << setprecision(15) << ans << endl;
    }
    return 0;
}