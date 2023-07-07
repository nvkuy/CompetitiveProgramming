#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> asterick, packman;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*')
            asterick.push_back(i);
        if (s[i] == 'P')
            packman.push_back(i);
    }
    int l = 0, r = 2 * n + 2, m;
    while (l < r) {
        m = (l + r) / 2;
        int j = 0;
        for (int p : packman) {
            if (j == asterick.size()) break;
            int t1 = asterick[j];
            if (p < t1) {
                while (j < asterick.size() && asterick[j] <= p + m) j++;
                continue;
            }
            if (p - t1 > m) break;
            while (j < asterick.size() && asterick[j] <= p) j++;
            while (true) {
                if (j == asterick.size()) break;
                if ((p - t1 + asterick[j] - t1) > m && (asterick[j] - p + asterick[j] - t1) > m) break;
                j++;
            }
        }
        if (j == asterick.size())
            r = m;
        else
            l = m + 1;
    }
    cout << r << endl;

    return 0;
}