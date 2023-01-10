#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

vector<pair<int, int>> shared_side(vector<int> &a, vector<int> &b) {
    vector<pair<int, int>> ans;
    if (a[0] == b[0]) {
        ans.push_back(mp(0, 0));
    }
    if (a[1] == b[0]) {
        ans.push_back(mp(1, 0));
    }
    if (a[1] == b[1]) {
        ans.push_back(mp(1, 1));
    }
    if (a[0] == b[1]) {
        ans.push_back(mp(0, 1));
    }
    return ans;
}

int inverse(int a) {
    if (a == 1) return 0;
    return 1;
}

bool solve(vector<int> r1,vector<int> r2, vector<int> r3) {
    vector<pair<int, int>> shared = shared_side(r1, r2);
    for (auto &p: shared) {
        int w = r1[p.first];
        int l = r1[inverse(p.first)] + r2[inverse(p.second)];
        vector<int> rect = {w, l};
        vector<pair<int, int>> rect_shared = shared_side(rect, r3);
        for (auto &p2: rect_shared) {
            int w = rect[p2.first];
            int l = rect[inverse(p2.first)] + r3[inverse(p2.second)];
            if (w == l) {
                cout << "YES" << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> r1(2);
    vector<int> r2(2);
    vector<int> r3(2);
    cin >> r1[0] >> r1[1] >> r2[0] >> r2[1] >> r3[0] >> r3[1];
    if (solve(r1, r2, r3)) return 0;
    if (solve(r1, r3, r2)) return 0;
    if (solve(r2, r3, r1)) return 0;
    cout << "NO";
    // two rectangles must share a side. Fit each way and see if the third is good;
    return 0;
}