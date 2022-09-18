#include <bits/stdc++.h>

using namespace std;

int cmo(string s1, string s2) {
    int i = 0, j = 0, c = 0;
    while (true) {
        while (s1[j] != s2[i]) {
            i++;
            c++;
            if (i >= s2.length())
                break;
        }
        if (i >= s2.length())
            break;
        j++;
        i++;
        if (j >= s1.length() || i >= s2.length())
            break;
    }
    if (j >= s1.length() && i < s2.length())
        return c + s2.length() - i;
    return s1.length() - j + c;
}

int main()
{
    long long t;
    t = 1;
    vector<string> po2;
    while (t <= 1e18) {
        po2.push_back(to_string(t));
        t *= 2;
    }
    cin >> t;
    string n;
    cin.ignore();
    while (t--) {
        getline(cin, n);
        int ans = n.length() + 1;
        for (int i = 0; i < po2.size(); i++) {
            ans = min(ans, cmo(po2[i], n));
            //cout << po2[i] << '|' << n << ':' << cmo(po2[i], n) << endl;
        }
        cout << ans << endl;
    }
    /*
    long long t;
    t = 1;
    set<string> check;
    while (t <= 1e11) {
        check.insert(to_string(t));
        t *= 2;
    }
    cin >> t;
    string n, v;
    cin.ignore();
    while (t--) {
        getline(cin, n);
        set<string> s;
        set<string>::iterator it;
        queue<pair<string, int>> q;
        s.insert(n);
        q.push(make_pair(n, 0));
        int ans = n.length() + 1;
        while (!q.empty()) {
            pair<string, int> u = q.front();
            q.pop();
            it = check.find(u.first);
            if (it != check.end()) {
                ans = min(ans, u.second);
                continue;
            }
            if (u.second >= ans)
                continue;
            if (u.first.length() <= 1)
                ans = min(ans, u.second + 2);
            else {
                for (int i = 0; i < u.first.length(); i++) {
                    v = u.first;
                    v.erase(v.begin() + i);
                    it = s.find(v);
                    if (it == s.end()) {
                        q.push(make_pair(v, u.second + 1));
                        s.insert(v);
                    }
                }
            }
            if (u.first.length() <= n.length() + 1) {
                for (char i = '0'; i <= '9'; i++) {
                    v = u.first;
                    v.push_back(i);
                    it = s.find(v);
                    if (it == s.end()) {
                        q.push(make_pair(v, u.second + 1));
                        s.insert(v);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    */

    return 0;
}
