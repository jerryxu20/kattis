#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n, m;

set<string> seen;

string flatten(vector<string> &state) {
    string res = "";
    for (auto &row: state) res += row;
    return res;
}

void backtrack(vector<string> &state, vector<int> &arr, int idx) {
    if(idx == m) {


        for (auto &row: state) {
            for (auto &cell: row) {
                if (cell == 'O') return;
            }
        }
        ans++;
        return;
    }

    // place it horizontal somewhere
    int l = arr[idx];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + l - 1 < n; j++) {
            int taken = 0;
            for (int k = j; k < j + l; k++) {
                if (state[i][k] == 'X' || state[i][k] == 'T') {
                    taken++;
                }
            }

            if (taken) continue;
            string row = state[i];
            for (int k = j; k < j + l; k++) {
                state[i][k] = 'T';
            }
            backtrack(state, arr, idx + 1);
            state[i] = row;
        }
    }

    if (l == 1) return;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int taken = 0;
            for (int k = i; k < i + l; k++) {
                if (state[k][j] == 'X' || state[k][j] == 'T') {
                    taken++;
                }
            }
            if (taken) continue;
            string row;
            for (int k = i; k < i + l; k++) {
                row.push_back(state[k][j]);
                state[k][j] = 'T';
            } 
            backtrack(state, arr, idx + 1);
            for (int k = i; k < i + l; k++) {
                state[k][j] = row[k - i];
            } 
        }
    }
}


int main() {
    cin >> n >> m;
    vector<string> state(n);
    for (auto &s: state) cin >> s;

    vector<int> len(m);
    for (int &x: len) cin >> x;

    sort(len.begin(), len.end(), greater<int>());
    backtrack(state, len, 0);
    cout << ans << endl;


}