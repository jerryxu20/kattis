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
    int q;
    cin >> q;
    for (int t = 1; t <= q; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> img(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> img[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(img[i].begin(), img[i].end()); // flip horizontal
        }
        for (int j = 0; j < m; j++) {
            int low = 0;
            int high = n - 1;
            while (low <= high) {
                swap(img[low][j], img[high][j]);
                low++;
                high--;
            }
        }
        cout << "Test " << t << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << img[i][j];
            }
            cout << '\n';
        } 
    }
    return 0;
}