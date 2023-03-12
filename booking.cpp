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


class date {
public:
    int year;
    int month;
    int day;
    int mins;
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date(string ymd, string time) {
        year = stoi(ymd.substr(0, 4));
        month = stoi(ymd.substr(5, 7));
        day = stoi(ymd.substr(8, 10));
        mins = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    }
    date& operator+(int n) {
        mins += n;
        if (mins > 24 * 60) {
            day++;
        }
        mins %= (24 * 60);
        if (day > sizeofmonth()) {
            month++;
            day = 1;
        }
        if (month > 12) {
            month = 1;
            year++;
        }
        return *this;
    }

    date& operator+=(int n) {
        return *this + n;
    }

    int sizeofmonth() {
        if (year == 2016 && month == 2) {
            return 29;
        }
        return days[month];
    }
};

bool operator<(const date &a, const date &b) {
    if (a.year == b.year && a.month == b.month && a.day == b.day) {
        return a.mins < b.mins;
    }
    if (a.year == b.year && a.month == b.month) {
        return a.day < b.day;
    }
    if (a.year == b.year) {
        return a.month < b.month;
    }
    return a.year < b.year;
}

bool operator<=(const date &a, const date &b) {
    if (a.year == b.year && a.month == b.month && a.day == b.day) {
        return a.mins <= b.mins;
    }
    if (a.year == b.year && a.month == b.month) {
        return a.day <= b.day;
    }
    if (a.year == b.year) {
        return a.month <= b.month;
    }
    return a.year <= b.year;
}

struct smallestFirst
{
    bool operator() (date &a,  date &b) { return !(a < b); }
};

ostream &operator << (ostream &out, const date &d) {
    out << d.year << "-" << d.month << "-" << d.day << " ";
    out << d.mins;
    return out;
}

int main() {
    int t, B, C;
    string id, ymd, time;
    cin >> t;
    // 2016 is a leap year
    while (t--) {
        cin >> B >> C;
        vector<pair<date, date>> bookings;
        while (B--) {
            cin >> id;
            cin >> ymd >> time;
            date arr = date(ymd, time);
            cin >> ymd >> time;
            date leave = date(ymd, time);
            leave += C;
            bookings.pb(mp(arr, leave));
        }
        sort(all(bookings), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        int ans = 0;
        int free = 0;
        priority_queue<date, vector<date>, smallestFirst> pq;
        for (auto [a, b]: bookings) {
            while (!pq.empty() && pq.top() <= a) {
                free++;
                pq.pop();
            }
            if (free == 0) {
                free++;
                ans++;
            }
            pq.push(b);
            free--;
        }
        cout << ans << endl;
    }
    return 0;
}