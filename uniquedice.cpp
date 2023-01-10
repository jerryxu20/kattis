#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void permute(vector<int> &sides, vector<int> &mn, vector<int> &cand) {
    vector<int> body = {sides[2], sides[4], sides[3], sides[5]};
    for (int i = 0; i < 4; i++) {
        int idx = i;
        for (int j = 2; j < 6; j++) {
            cand[j] = body[idx];
            idx++;
            idx %= 4;
        }
        mn = min(mn, cand);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    map<vector<int>, int> freq;
    vector<int> sides(6);
    vector<int> mn;
    vector<int> cand;
    int ans = 0;
    while (n--) {
        for (int &side: sides) {
            cin >> side;
        }
        mn = {6, 6, 6, 6, 6, 6};
        cand = sides;
        permute(sides, mn, cand);
        
        swap(sides[0], sides[1]);
        swap(sides[2], sides[3]);
        cand = sides;
        permute(sides, mn, cand);

        swap(sides[0], sides[2]);
        swap(sides[1], sides[3]);
        swap(sides[0], sides[1]);
        cand = sides;
        permute(sides, mn, cand);
        
        swap(sides[0], sides[1]);
        swap(sides[2], sides[3]);
        cand = sides; 
        permute(sides, mn, cand);

        swap(sides[0], sides[4]);
        swap(sides[1], sides[5]);
        swap(sides[0], sides[1]);
        cand = sides;
        permute(sides, mn, cand);
 
        swap(sides[0], sides[1]);
        swap(sides[2], sides[3]);
        cand = sides;
        permute(sides, mn, cand);

        ans = max(ans, ++freq[mn]);
    }
    cout << ans << endl;
}