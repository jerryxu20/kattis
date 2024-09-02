#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 40;
int pos[MAXN], color[MAXN];
char dir[MAXN];
long long ans[MAXK];
int k;

vector<int> adjust(vector<int> &arr, int mod) {
    vector<int> narr(k);
    for (int i = 0; i < k; i++) {
        narr[(i + mod) % k] = arr[i]; 
    }
    return narr;
}

int main() {
    int n, l; cin >> n >> k >> l;

    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> color[i] >> dir[i];
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        return pos[a] < pos[b];
    });


    int prev = -1;
    int first = -1;
    int m = 0;
    vector<int> cur(k);
    for (int &i: idx) {
        int x = pos[i];
        if (dir[i] == 'D') {
            ans[color[i]] += 2 * (l - x);
            m += color[i];
            m %= k;
            
            if (prev != -1) {
                int delta = x - prev;
                cur = adjust(cur, color[i]);
                cur[color[i]] += delta; 
            } else {
                first = x;
            }
            prev = x;
            continue;
        }
        if (first == -1) {
            ans[color[i]] += 2 * x;
            continue;
        }

        int lastcolor = (color[i] + m) % k;
        ans[lastcolor] += x + first; 
        ans[color[i]] += x - prev;

        vector<int> dis = adjust(cur, color[i]);
        for (int j = 0; j < k; j++) {
            ans[j] += dis[j];
        }
    }

    cout << setprecision(1) << fixed;
    for (int i = 0; i < k; i++) {
        cout << ans[i]/2.0 << endl;
    }

}