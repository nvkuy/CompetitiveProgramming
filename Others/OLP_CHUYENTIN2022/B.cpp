#include <bits/stdc++.h>
using namespace std;

int sti(string &s, int l, int r) {
    string tmp = s.substr(l, r - l + 1);
    if (tmp.length() > 1 && tmp[0] == '0')
        return 1e7;
    return stoi(tmp);
}

int main() {

    string m;
    cin >> m;
    int ans = 1e9;
    for (int i = 0; i < m.length(); i++) {
        for (int j = i + 1; j + 1 < m.length(); j++) {
            ans = min(ans, sti(m, 0, i) + sti(m, i + 1, j) + sti(m, j + 1, m.length() - 1));
        }
    }
    cout << ans << endl;

    return 0;
}