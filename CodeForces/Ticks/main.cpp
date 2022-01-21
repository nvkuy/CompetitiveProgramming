#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, kk;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m >> kk;
        int co = 0;
        cin.ignore();
        vector<vector<bool>> c(n + 1, vector<bool>(m + 1, false)), dd(n + 1, vector<bool>(m + 1, false));
        for (int i = 1; i <= n; i++) {
            getline(cin, s);
            for (int j = 1; j <= m; j++) {
                if (s[j - 1] == '*') {
                    c[i][j] = true;
                    co++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((!c[i][j]) || (dd[i][j]))
                    continue;
                int d1 = 0, d2 = 0;
                int k = 1;
                while (j - k > 0 && i - k > 0) {
                    if (c[i - k][j - k])
                        d1++;
                    else
                        break;
                    k++;
                }
                k = 1;
                while (j + k <= m && i - k > 0) {
                    if (c[i - k][j + k])
                        d2++;
                    else
                        break;
                    k++;
                }
                k = min(d1, d2);
                if (k < kk)
                    continue;
                for (int l = 0; l <= k; l++) {
                    if (!dd[i - l][j - l]) {
                        dd[i - l][j - l] = true;
                        co--;
                    }
                }
                for (int l = 0; l <= k; l++) {
                    if (!dd[i - l][j + l]) {
                        dd[i - l][j + l] = true;
                        co--;
                    }
                }
            }
        }
        cout << ((co <= 0) ? "YES" : "NO") << '\n';
    }

    return 0;
}
