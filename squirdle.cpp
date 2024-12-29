#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
int bad[MAXN], notright[MAXN][5], pos[MAXN];
set<char> confirmed;

void guess(string s) {
    string res;
    cout << "? " << s << endl;
    cin >> res;

    for (int i = 0; i < 5; i++) {
        if (res[i] == '0') {
            bad[s[i]] = 1;
        } else if (res[i] == '1') {
            confirmed.insert(s[i]);
            notright[s[i]][i] = 1;
        } else {
            confirmed.insert(s[i]);
            pos[s[i]] = i;
        }
    }

    if (res == "22222") exit(0);
}


bool valid(string &s) {
    for (int i = 0; i < 5; i++) {
        if (pos[s[i]] != -1 && pos[s[i]] != i) return false;
        if (notright[s[i]][i]) return false;
    }
    return true;
}


int main() {
    memset(pos, -1, sizeof(pos));

    string a = "abcde";
    string b = "fghij";
    string c = "klmno";
    string d = "pqrst";
    string e = "uvwxy";

    guess(a);
    guess(b);
    guess(c);
    guess(d);
    guess(e);

    if (confirmed.size() != 5) {
        confirmed.insert('z');
    }

    string s;
    for (auto &c: confirmed) {
        s.push_back(c);
    }
    do {
        if (valid(s)) {
            guess(s);
        }
    } while(next_permutation(s.begin(), s.end()));

}