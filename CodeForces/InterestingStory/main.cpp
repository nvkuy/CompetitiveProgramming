#include <bits/stdc++.h>

using namespace std;

struct word {
    int co[5];
    word(string s) {
        memset(co, 0, sizeof(co));
        for (int i = 0; i < s.length(); i++)
            co[s[i] - 'a']++;
    }
    int dt(char c) {
        int i = c - 'a';
        int s = 2 * co[i];
        for (int j = 0; j < 5; j++)
            s -= co[j];
        return s;
    }
};

int cal(char c, vector<word> ws) {
    int co = 0, s = 0, tmp;
    vector<int> rc;
    for (int i = 0; i < ws.size(); i++) {
        tmp = ws[i].dt(c);
        if (tmp > 0) {
            co++;
            s += tmp;
        } else
            rc.push_back(tmp);
    }
    sort(rc.begin(), rc.end(), greater<int>());
    for (int i = 0; i < rc.size(); i++) {
        if (s + rc[i] > 0) {
            s += rc[i];
            co++;
        } else
            break;
    }
    return co;
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        vector<word> ws;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            ws.push_back(word(s));
        }
        int ans = 0;
        for (char c = 'a'; c <= 'e'; c++)
            ans = max(ans, cal(c, ws));
        cout << ans << endl;
    }

    return 0;
}
