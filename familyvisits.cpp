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
    int n, d, day;
    cin >> n >> d;
    vector<int> mess(n + 1);
    vector<int> clean(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> mess[i] >> clean[i];
    }
    int prevday = 0;
    int ans = 0;
    while(d--) {
        cin >> day;
        priority_queue<int> pq;
        int overclean = 0;
        for (int i = day; i > prevday; i--) {
            pq.push(clean[i]);
            int cap = min(overclean, mess[i]);
            mess[i] -= cap;
            overclean -= cap;
            // cout << i << " " << mess[i] << " " << overclean << " " << pq.top() << endl;
            while (mess[i] > 0 && !pq.empty()) {
                overclean += max(0, pq.top() - mess[i]);
                mess[i] -= pq.top();
                pq.pop();
                ans++;
            }
            if (pq.empty() && mess[i] > 0) {
                cout << - 1 << endl;
                return 0;
            }
        }
        prevday = day;
    }
    cout << ans << endl;
    return 0;
}