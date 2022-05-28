#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmpSTR(string &s1, string &s2) {
    int rm1 = s1.length() % 2, rm2 = s2.length() % 2;
    if (rm1 == rm2)
        return s1.length() < s2.length();
    return rm1 < rm2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b, c, d;
    string s;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin.ignore();
        getline(cin, s);
        int n = s.length();
        vector<string> as;
        string tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(s[i]);
            if (i + 1 >= n || s[i] == s[i + 1]) {
                as.push_back(tmp);
                tmp.clear();
            }
        }
        sort(as.begin(), as.end(), cmpSTR);
        for (int i = 0; i < as.size(); i++) {
            tmp = as[i];
            if (tmp.length() == 1) {
                if (tmp[0] == 'A')
                    a--;
                else
                    b--;
                continue;
            }
            if (tmp.length() % 2) {
                int t1 = tmp.length() / 2;
                int t2 = min(t1, c);
                c -= t2, t1 -= t2;
                t2 = min(t1, d);
                d -= t2, t1 -= t2;
                if (tmp[0] == 'A')
                    a--;
                else
                    b--;
                while (t1 > 0)
                    t1--, a--, b--;
            } else {
                int t1 = tmp.length() / 2;
                if (tmp[0] == 'A') {
                    int t2 = min(t1, c);
                    c -= t2, t1 -= t2;
                    if (t1 > 0)
                        t1--, a--, b--;
                    t2 = min(t1, d);
                    t1 -= t2, d -= t2;
                    while (t1 > 0)
                        t1--, a--, b--;
                } else {
                    int t2 = min(t1, d);
                    d -= t2, t1 -= t2;
                    if (t1 > 0)
                        t1--, a--, b--;
                    t2 = min(t1, c);
                    t1 -= t2, c -= t2;
                    while (t1 > 0)
                        t1--, a--, b--;
                }
            }
        }
        if (a > 0 || b > 0 || c > 0 || d > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
