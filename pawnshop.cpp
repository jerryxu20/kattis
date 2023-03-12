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
    int N, a;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> freq;
    int unresolved = 0;
    string ans = "";
    for (int i = 0; i < N; i++) {
        cin >> a;
        ans += to_string(a);
        ans += ' ';
        freq[A[i]]++;
        if (freq[A[i]] == 0) unresolved--;
        if (freq[A[i]] == 1) unresolved++;
        freq[a]--;
        if (freq[a] == 0) unresolved--;
        if (freq[a] == -1) unresolved++;
        if (unresolved == 0) ans += "# ";
    }
    ans.pop_back();
    ans.pop_back();
    cout << ans << endl;
    return 0;
}