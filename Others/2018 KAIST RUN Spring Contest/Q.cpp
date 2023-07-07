#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s, cur = "";
    cin >> s;
    vector<vector<int>> c;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            if (c.size() > 0) {
                ans -= c.back().size();
                c.pop_back();
                cur.pop_back();
            }
        } else {
            vector<int> tmp(1, cur.length());
            if (c.size() > 0) {
                for (int p : c.back()) {
                    if (p + 1 == cur.length() && cur[p] == s[i])
                        tmp.push_back(p);
                    if (p > 0 && cur[p - 1] == s[i])
                        tmp.push_back(p - 1);
                }
            }
            c.push_back(tmp);
            cur.push_back(s[i]);
            ans += c.back().size();
        }
        cout << ans << ' ';
        //cout << "@ans " << ans << endl;
        //cout << "@cur " << cur << endl;
        //cout << "@tmp ";
        //for (int ai : c.back()) cout << ai << ' ';
        //cout << endl;
    }
    cout << endl;

    return 0;
}
