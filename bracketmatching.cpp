#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    string stack;
    for (char &c: s) {
        if (c == ')') {
            if (stack.empty() || stack.back() != '(') {
                cout << "Invalid\n";
                return 0;
            }
            stack.pop_back();
        } else if (c == '}') {
            if (stack.empty() || stack.back() != '{') {
                cout << "Invalid\n";
                return 0;
            }
            stack.pop_back();
        } else if (c == ']') {
            if (stack.empty() || stack.back() != '[') {
                cout << "Invalid\n";
                return 0;
            }
            stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }

    if (stack.empty()) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }
}