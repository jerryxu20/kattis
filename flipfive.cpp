#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

map<vector<vector<bool>>, int> ans;
vector<vector<bool>> start = {{true, true, true}, {true, true, true}, {true, true, true}};
queue<vector<vector<bool>>> q;
int d = 0;
vector<vector<int>> delta = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int helper() {
    while(ans.size() < 512) {
        cout << ans.size() << endl;
        int sz = q.size();
        while(sz--) {
            auto grid = q.front();
            ans[grid] = d;
            q.pop();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    vector<vector<bool>> game = grid;
                    for (auto &v: delta) {
                        if (i + v[0] < 0 || j + v[1] < 0 || i + v[0] >= 3 || j + v[1] >= 3) continue;
                        game[i + v[0]][j + v[1]] = !game[i + v[0]][j + v[1]];
                    }
                    if (ans.count(game)) continue;
                    q.push(game);
                }
            }
        }
        d++;
    }
    cout << ans.size() << endl;
    return -1;

}


int main() {
    ans[start] = 0;
    q.push(start);
    helper();
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << "ans[{";
        for (int i = 0; i < 3; i++) {
            cout << "{";
            for (int j = 0; j < 3; j++) {
                if (it->first[i][j]) {
                    cout << "true";
                } else {
                    cout << "false";
                }
                if (j < 2) {
                    cout << ",";
                } 
            }
            cout << "}";
            if (i < 2) {
                cout << ",";
            }
        }
        cout << "}] = ";
        cout << it->second << ";\n";
    }
    return 0;
}