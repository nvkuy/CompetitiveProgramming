#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> f(26, vector<int>(n + 1, 0));
    for (int c = 0; c < 26; c++) {
        for (int m = 0; m <= n; m++) {
            int j = 0, cnt = 0, ans = 0;
            for (int i = 0; i < n; i++) {
                cnt += ((s[i] - 'a') != c);
                while (cnt > m) {
                    cnt -= ((s[j] - 'a') != c);
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
            f[c][m] = ans;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        cout << f[c - 'a'][m] << endl;
    }

    return 0;
}
