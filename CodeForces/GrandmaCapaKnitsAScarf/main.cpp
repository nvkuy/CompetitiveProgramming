#include <bits/stdc++.h>

using namespace std;

pair<int, int> cp(string s, char c, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] == c) {
            i++;
            continue;
        }
        if (s[j] == c) {
            j--;
            continue;
        }
        if (s[i] != s[j])
            return make_pair(-1, -1);
        i++; j--;
    }
    if (i > j) {
        i--;
        j++;
    }
    return make_pair(i + 1, j + 1);
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(33, 0));
        cin.ignore();
        getline(cin, s);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 'z' - 'a'; j++)
                a[i][j] = a[i - 1][j];
            a[i][s[i - 1] - 'a']++;
            //cout << a[i][0] << '|' << a[i][1] << '|' << a[i][2] << endl;
        }
        int ans = 1e9 + 7;
        for (char c = 'a'; c <= 'z'; c++) {
            pair<int, int> p = cp(s, c, n);
            if (p.first == -1)
                continue;
            ans = min(ans, abs(a[p.first][c - 'a'] - (a[n][c - 'a'] - a[p.second][c - 'a'])));
        }
        if (ans >= 1e9)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}
