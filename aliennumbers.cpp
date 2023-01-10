#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair



int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        string num;
        string source, target;
        cin >> num >> source >> target;
        map<char, int> src;
        for (int i = 0; i < (int)source.length(); i++) {
            src[source[i]] = i;
        }
        int og = 0;
        reverse(all(source));
        int a = source.length();
        for (char &c: num) {
            og *= a;
            og += src[c];
        }
        int b = target.length();
        string ans = "";
        while(og > 0) {
            int m = og % b;
            ans += target[m];
            og /= b;         
        }
        reverse(all(ans));
        cout << "Case  #" << test << ": " << ans << endl; 
    }
    return 0;
}