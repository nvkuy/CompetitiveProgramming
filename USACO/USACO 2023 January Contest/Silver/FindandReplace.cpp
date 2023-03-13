#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        map<char, char> ks;
        set<pair<char, char>> done;
        set<char> tmp;
        int n = s1.length(), middle = 0;
        bool isValid = true;
        for (int i = 0; i < n; i++) {
            if (!isValid) break;
            if (done.find({s1[i], s2[i]}) != done.end()) continue;
            if (s1[i] == s2[i]) {
                if (ks.find(s1[i]) != ks.end())
                    isValid = false;
                continue;
            }
            if (ks.find(s1[i]) != ks.end() && ks[s1[i]] != s2[i]) {
                isValid = false;
                continue;
            }
            if (tmp.find(s1[i]) != tmp.end()) {
                middle++;
                ks[s1[i]] = s2[i];
                done.insert({s1[i], s2[i]});
                continue;
            }
            ks[s1[i] = s2[i]];
            tmp.insert(s2[i]);
        }
        set<char> used;
        for (char c : s1) used.insert(c);
        for (char c : s2) used.insert(c);
        if (middle + used.size() > 26 * 2)
            isValid = false;
        cout << (isValid ? middle + ks.size() : -1) << endl;
    }

    return 0;
}