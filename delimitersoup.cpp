#include <bits/stdc++.h>
using namespace std;


int main() {
    int a;
    cin >> a;
    string s;
    getline(cin, s);
    getline(cin, s);
    // cout << s << ' ';
    vector<char> brackets;
    for (int i = 0; i < a; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            brackets.push_back(s[i]);
        } else if (s[i] == ']' || s[i] == ')' || s[i] == '}'){
            if (brackets.size() == 0) {
                cout << s[i] << ' ' << i;
                return 0;
            }
            bool good = false;
            if (s[i] == ')' && brackets.back() == '(') {
                good = true;
            } else if (s[i] == '}' && brackets.back() == '{') {
                good = true;
            } else if (s[i] == ']' && brackets.back() == '[') {
                good = true;
            }
            if (good) {
                brackets.pop_back();
            } else {
                cout << s[i] << ' ' << i;
                return 0;
            }
        }
    }
    cout << "ok so far";
    return 0;
}