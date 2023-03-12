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
    int n, t;
    cin >> n >> t;
    vector<pii> q(n);
    for (auto &[a, b]: q) {
        cin >> a >> b;
    }
    sort(all(q), [] (auto &a, auto &b) {
        return a.second < b.second;
    });
    int total = 0;
    priority_queue<int> pq;
    for (int i = t; i >= 0; i--) {
        while(sz(q) > 0 && q.back().second >= i) {
            pq.push(q.back().first);
            q.pop_back();
        }
        if (sz(pq)) {
            total += pq.top();
            pq.pop();
        }
    }
    cout << total << endl;
    return 0;
}