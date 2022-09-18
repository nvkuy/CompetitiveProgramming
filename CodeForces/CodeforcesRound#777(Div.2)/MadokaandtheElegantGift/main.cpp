#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<bool>> c(n);
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for (int j = 0; j < m; j++) {
                if (s[j] == '1')
                    c[i].push_back(1);
                else
                    c[i].push_back(0);
            }
        }
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (!iok)
                break;
            for (int j = 0; j < m; j++) {
                if (!iok)
                    break;
                if (i > 0 && j + 1 < m) {
                    if ((c[i][j] & c[i - 1][j] & c[i][j + 1]) == true && c[i - 1][j + 1] == false)
                        iok = false;
                }
                if (i > 0 && j > 0) {
                    if ((c[i][j] & c[i - 1][j] & c[i][j - 1]) == true && c[i - 1][j - 1] == false)
                        iok = false;
                }
                if (i + 1 < n && j > 0) {
                    if ((c[i][j] & c[i + 1][j] & c[i][j - 1]) == true && c[i + 1][j - 1] == false)
                        iok = false;
                }
                if (i + 1 < n && j + 1 < m) {
                    if ((c[i][j] & c[i + 1][j] & c[i][j + 1]) == true && c[i + 1][j + 1] == false)
                        iok = false;
                }
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
