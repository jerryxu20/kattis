#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

const int MOD_INT = 1e9 + 7;
const ll MOD = 1e9 + 7;


int main() {
    int n, c, x;
    while (cin >> n) {
        priority_queue<int> pq;
        vector<int> stack;
        queue<int> q;
        vector<int> passed (3);
        int total = 0;
        while (n--) {
            cin >> c;
            if (c == 1) {
                cin >> x;
                pq.push(x);
                stack.push_back(x);
                q.push(x);
            } else {
                total++;
                cin >> x;
                if (stack.empty()) continue;
                if (pq.top() == x) {
                    passed[0]++;
                }
                if (stack.back() == x) {
                    passed[1]++;
                }
                if (q.front() == x) {
                    passed[2]++;
                }
                q.pop();
                pq.pop();
                stack.pop_back();
            }
        }
        vector<int> ans;
        for (int i = 0; i < 3; i++) {
            if (passed[i] == total) {
                ans.push_back(i);
            }
        }
        int sz = ans.size();
        if (sz == 0) {
            cout << "impossible\n";
            continue;
        } else if (sz > 1) {
            cout << "not sure\n";
            continue;
        }
        if (ans[0] == 0) {
            cout << "priority queue\n";
        }
        if (ans[0] == 1) {
            cout << "stack\n";
        }
        if (ans[0] == 2) {
            cout << "queue\n";
        }
        
    }
    
    return 0;
}