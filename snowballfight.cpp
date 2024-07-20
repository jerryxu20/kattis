#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    while(A && B && C) {
        if (A > 3 && B == C && A == B - 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (B > 3 && A == C && B == A - 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }


        if (C > 3 && A == B && C == B - 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        // x, x, x + 1
        if (A > 5 && B == C && A == B + 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (B > 5 && A == C && B == A + 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (C > 5 && A == B && C == B + 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (min({A, B, C}) > 10 && max({A, B, C}) - min({A, B, C}) == 1) {
            ll rounds = min({A/3, B/3, C/3});
            A -= rounds * 3;
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }


        if (A + 4 < B && A + 4 < C && abs(B - C) == 0) {
            ll rounds = min((B - A)/3, (C - A)/3);
            B -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (B + 4 < A && B + 4 < C && abs(A - C) == 0) {
            ll rounds = min((A - B)/3, (C - B)/3);
            A -= rounds * 3;
            C -= rounds * 3;
            continue;
        }

        if (C + 4 < A && C + 4 < B && abs(A - B) == 0) {
            ll rounds = min((A - C)/3, (B - C)/3);
            A -= rounds * 3;
            B -= rounds * 3;
            continue;
        }

        if (B == C && A > B + 4) {
            ll rounds = min({B, C, (A - B + 1)/3}) -1;
            if (rounds) {
                B -= rounds;
                C -= rounds;
                A -= 4 * rounds;
                continue;
            }
        }
        
        if (A == C && B > A + 4) {
            ll rounds = min({A, C, (B - A)/3}) - 1;
            if (rounds) {
                B -= 4 * rounds;
                C -= rounds;
                A -= rounds;
                continue;

            }
        }
        
        if (A == B && C > A + 4) {
            ll rounds = min({A, B, (C - A)/3}) - 1;
            if (rounds) {
                B -= rounds;
                C -= 4 * rounds;
                A -= rounds;
                continue;
            }


        }


        ll da = 0, db = 0, dc = 0;

        // for A
        if (B >= C) db++;
        else dc++;


        // for B
        if (C >= A) dc++;
        else da++;

        // for C
        if (A >= B) da++;
        else db++;

        ll rounds = min({A, B, C});
        if (da) rounds = min(rounds, (A + da - 1)/da);
        if (db) rounds = min(rounds, (B + db - 1)/db);
        if (dc) rounds = min(rounds, (C + dc - 1)/dc);

        // for A
        if (B >= C) {
            if (db > dc) {
                ll r = (B - C)/(db - dc) + 1;
                rounds = min(rounds, r);
            }
        } else {
            if (dc > db) {
                ll r = (C - B + dc - db - 1)/(dc - db);
                rounds = min(rounds, r);
            }
        }

        if (C >= A) {
            if (dc > da) {
                ll r = (C - A)/(dc - da) + 1;
                rounds = min(rounds, r);
            }
        } else {
            if (da > dc) {
                ll r = (A - C + da - dc - 1)/(da - dc);
                rounds = min(rounds, r);
            }
        }

        // A >= B
        if (A >= B) {
            if (da > db) {
                ll r = (A - B)/(da - db) + 1;
                rounds = min(rounds, r);
            }
        } else {
            if (db > da) {
                ll r = (B - A + db - da - 1)/(db - da);
                rounds = min(rounds, r);
            }
        }

        assert(rounds > 0);
        A -= rounds * da;
        B -= rounds * db;
        C -= rounds * dc;

        A = max(A, 0LL);
        B = max(B, 0LL);
        C = max(C, 0LL);
    }
    // cout << A << " " << B << " " << C << endl;
    int x = max({A, B, C});

    int cnt = 0;
    if (A == x) cnt++;
    if (B == x) cnt++;
    if (C == x) cnt++;

    if (cnt > 1) {
        cout << "Rubble!\n";
        return 0;
    } 

    int sm = A + B + C - x;

    A -= sm;
    B -= sm;
    C -= sm;

    if (A > 0) {
        cout << "A " << A << endl;
    } else if (B > 0) {
        cout << "B " << B << endl;
    } else {
        cout << "C " << C << endl;
    }


}