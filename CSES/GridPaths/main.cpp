#include <bits/stdc++.h>

using namespace std;

int f[1001][1001];
vector<string> m;

int main()
{
    int n, mi, mod = 1e9 + 7;
    string s;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        m.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '*') {
                f[i][j] = 0;
                continue;
            }
            if (i + j == 0)
                f[i][j] = 1;
            else {
                mi = 0;
                if (i > 0 && m[i - 1][j] == '.')
                    mi += f[i - 1][j];
                if (j > 0 && m[i][j - 1] == '.')
                    mi += f[i][j - 1];
                f[i][j] = mi % mod;
            }
            //cout << f[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << f[n - 1][n - 1] << '\n';

    return 0;
}
