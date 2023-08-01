#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> cnt;
        for (char c : s)
            cnt[c]++;
        vector<pair<char, int>> ansL, ansR;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            auto tit = it;
            tit++;
            if (tit != cnt.end()) {
                tit++;
                if (tit == cnt.end()) {
                    tit = it;
                    auto p1 = *tit;
                    ansL.push_back({p1.first, p1.second / 2});
                    ansR.push_back({p1.first, p1.second / 2});
                    tit++;
                    auto p2 = *tit;
                    ansL.push_back({p2.first, p2.second / 2});
                    ansR.push_back({p2.first, p2.second / 2});

                    ansL.push_back({p2.first, p2.second % 2});
                    ansL.push_back({p1.first, p1.second % 2});
                    break;
                }
            }
            auto p = *it;
            ansL.push_back({p.first, p.second / 2});
            ansR.push_back({p.first, p.second / 2});
            if (p.second % 2) {
                ansR.push_back({p.first, 1});
                tit = it;
                tit++;
                for (; tit != cnt.end(); tit++)
                    ansL.push_back(*tit);
                break;
            }
        }
        reverse(ansR.begin(), ansR.end());
        for (auto p : ansL)
            for (int i = 0; i < p.second; i++) cout << p.first;
        for (auto p : ansR)
            for (int i = 0; i < p.second; i++) cout << p.first;
        cout << endl;
    }

    return 0;
}