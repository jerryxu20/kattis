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
map<string, int> cast;
int idd = 0;
vector<int> adj[32];
string name[32];

int id(string &s) {
    if (cast.count(s)) return cast[s];
    cast[s] = idd++;
    name[cast[s]] = s;
    return cast[s];
}

void process(string &s) {
    int node = -1;
    s += ' ';
    string cur = "";
    for (auto &c: s) {
        cur += c;
        if (c == ' ') {
            if (node == - 1) {
                node = id(cur);
            } else {
                adj[node].pb(id(cur));
            }
            cur = "";
        }
    }
    return;
} 

bool dfs(int node, int t, vector<int> &path) {
    path.push_back(node);
    if (node == t) {
        cout << 1 << endl;
        return true;
    }
    for (auto &nxt: adj[node]) {
        if (dfs(nxt, t, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    int n;
    string a, b, s;
    cin >> n;
    while(n--) {
        getline(cin, s);
        process(s);
    }
    cin >> a >> b;
    int start = id(a);
    int t = id(b);
    for (int i = 0; i < 32; i++) {
        cout << name[i] << endl;
    }
    cout << start <<  " " << t << endl;
    vector<int> path;
    if (dfs(start, t, path)) {
        for (auto &node: path) {
            cout << name[node] << " ";
        }
        cout << endl;
    }
    return 0;
}