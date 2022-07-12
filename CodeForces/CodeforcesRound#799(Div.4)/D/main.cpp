#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void timeToString(int hh, int mm, string &s) {
    s.clear();
    if (hh < 10)
        s.push_back('0');
    s += to_string(hh);
    s.push_back(':');
    if (mm < 10)
        s.push_back('0');
    s += to_string(mm);
}

bool isPalindrome(string &s) {
    if (s[0] != s[4] || s[1] != s[3])
        return false;
    return true;
}

void nextLook(int &hh, int &mm, int x) {
    int addH = x / 60, addM = x % 60;
    if (mm + addM >= 60)
        addH++;
    mm = (mm + addM) % 60;
    hh = (hh + addH) % 24;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x;
    string s;
    cin >> t;
    while (t--) {
        cin >> s >> x;
        int hh = (s[0] - '0') * 10 + (s[1] - '0');
        int mm = (s[3] - '0') * 10 + (s[4] - '0');
        set<string> cnt;
        for (int i = 0; i <= 1440; i++) {
            timeToString(hh, mm, s);
            if (isPalindrome(s))
                cnt.insert(s);
            nextLook(hh, mm, x);
        }
        cout << cnt.size() << endl;
    }

    return 0;
}
