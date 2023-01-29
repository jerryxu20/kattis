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

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    TwoSat ts = TwoSat(c * 2);
    vector<vector<int>> grid(n, vector<int> (n, -1));
    int N = 0;
    // each grid has light l and l + 1
    int h, v;
    int a, b;
    while(c--) {
        cin >> a >> b;
        a--;
        b--;
        grid[a][b] = N;
        h = N++;
        v = N++;
        ts.either(h, v);
        ts.either(~h, ~v);
    }
    // for each lamp (A or B) and (not A or not B)
    int ii, jj;
    int lamp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -1) continue;
            lamp = grid[i][j];
            // search vertial downwards
            for (int k = 1; k <= 2*r; k++) {
                ii = i + k;
                if (ii >= n) break;
                if (grid[ii][j] != -1) {
                    ts.atMostOne({lamp, grid[ii][j]});
                }
            }
            for (int k = 1; k <= 2*r; k++) {
                jj = j + k;
                if (jj >= n) break;
                if (grid[i][jj] > 0) {
                    ts.atMostOne({lamp + 1, grid[i][jj] + 1});
                }
            }
        }
    }
    cout << ts.solve() << endl;
    return 0;
}