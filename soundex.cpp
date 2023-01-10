#include <bits/stdc++.h>
using namespace std;

int readChar(string &s, int &ans, int idx) {
    int c = s[idx];
    while (idx < s.length()) {
        if (s[idx] != c) break;
        idx++;
    }
    switch (c) {
        case 'B':
        case 'F':
        case 'P':
        case 'V':
            ans *= 10;
            ans += 1;
            break;
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z':
            ans *= 10;
            ans += 2;
            break;
        case 'D':
        case 'T':
            ans *= 10;
            ans += 3;
            break;
        case 'L':
            ans *= 10;
            ans += 4;
            break;
        case 'M':
        case 'N':
            ans *= 10;
            ans += 5;
            break;
        case 'R':
            ans *= 10;
            ans += 6;        
            break;
    }
    return idx;

}
int main() {
    string s;
    while (cin >> s) {
        int ans = 0;
        int idx = 0;
        int n = s.size();
        while(true) {
            idx = readChar(s, ans, idx);
            if (idx >= n) break;
        }
        cout << ans << "\n";
    }
    return 0;
}